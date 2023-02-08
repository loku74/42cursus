#pragma once

#include <string>

class Contact
{
public:
	Contact();

	~Contact();

	// getters
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getPhoneNumber(void);
	std::string	getDarkestSecret(void);

	// setters
	void		setFirstName(std::string to_set);
	void		setLastName(std::string to_set);
	void		setNickName(std::string to_set);
	void		setPhoneNumber(std::string to_set);
	void		setDarkestSecret(std::string to_set);

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
};
