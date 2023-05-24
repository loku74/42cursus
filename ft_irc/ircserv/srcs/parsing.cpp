#include "../includes/parsing.hpp"
#include "../includes/Server.hpp"

void	split(const std::string& str, const char delim, std::vector<std::string>& out)
{
	std::stringstream   ss(str);

	std::string s;
	while (std::getline(ss, s, delim))
	{
		if (*s.rbegin() == '\r')
			s = s.substr(0, s.size() - 1);
		if (s.size() > 0)
			out.push_back(s);
	}
}

std::string const	strToUpper(std::string const & ref)
{
	std::string upper(ref);

	for (int i = 0; upper[i]; i++)
		upper[i] = static_cast<char>(std::toupper(upper[i]));

	return (upper);
}

void	Server::_parsing(const int socket, std::string& buffer)
{
	std::string				    command, message;
    std::vector<std::string>    arr;
    size_t                      n;
    s_args                      args;

	std::cout << CYAN "Buffer received: " << buffer << WHITEENDL;

	std::string line(buffer.size() + 17, '-');
	std::cout << line << std::endl;

    n = buffer.find(" :");

    if (n != std::string::npos)
    {
        // skips the first space
        n += 1;

        if (buffer[n])
        {
            message = buffer.substr(n, buffer.size() - n);
            buffer.erase(n - 1, buffer.size() - n + 1);
        }
    }

    split(buffer, ' ', arr);
    if (arr.size() > 0)
    {
        command = arr[0];
        arr.erase(arr.begin());
    }

    if (_functions.find(command) == _functions.end())
    {
        std::string msg;
        msg = ERR_UNKNOWNCOMMAND(_users[socket]->getNickname(), command);
        send(socket, msg.c_str(), msg.size(), 0);
        return ;
    }

    if (message.size())
        arr.push_back(message);

    args.args = arr;
    args.command = strToUpper(command);
    args.argCount = arr.size();
    args.args.push_back("");
    args.args.push_back("");

    (*this.*(_functions[command]))(socket, args);

}
