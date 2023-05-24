#include "Bot.hpp"

void	execute(Bot & bot, t_cmd const & cmd, t_info const & info)
{
	std::string quoi;

	if (cmd.arg.size() >= 6)
	{
		quoi = std::string(cmd.arg, cmd.arg.size() - 6, 4);
		std::cout << "quoi: " << quoi << std::endl;
	}

	std::cout << "cmd: " << cmd.cmd << std::endl;
	std::cout << "arg: " << cmd.arg << std::endl;
	if (info.type & PRIVATE)
		std::cout << "PRIVATE" << std::endl;
	else if (info.type & CHANNEL)
		std::cout << "CHANNEL" << std::endl;

	if (info.type & PRIVATE && cmd.cmd == "join" && cmd.arg != "")
		bot.sendData("on s'en fout normalement", cmd.arg, JOIN);
	else if (info.type & PRIVATE && cmd.cmd == "part" && cmd.arg != "")
		bot.sendData("on s'en fout pas normalement", cmd.arg, PART);
	else if (info.type & PRIVATE && cmd.cmd == "disconnect")
		bot.stopBot();
	else if (info.type & CHANNEL && cmd.cmd == "ircserv")
	{
		bot.sendData("\t_____\t______\t\t_____\t\t_____\t______\t\t_\t\t\t_\t", info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("|_\t\t\t_||\t___\t\\/\t\t__\t\\/\t___|\t|\t___\t\\|\t|\t|\t|", info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t|\t|\t\t|\t|_/\t/|\t/\t\t\\/\\\t`--.\t|\t|_/\t/|\t|\t|\t|", info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t|\t|\t\t|\t\t\t\t/\t|\t|\t\t\t\t\t`--.\t\\|\t\t\t\t/\t|\t|\t|\t|", info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t_|\t|_\t|\t|\\\t\\\t|\t\\__/\\/\\__/\t/|\t|\\\t\\\t\\\t\\_/\t/", info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\\___/\t\\_|\t\\_|\t\\____/\\____/\t\\_|\t\\_|\t\\___/\t", info.receiver, PRIVMSG | CHANNEL);
	}
	else if (info.type & CHANNEL && cmd.cmd == "sus")
	{
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\tO\t7\t0\tq\tq\tq\t9\t4\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t@\tq\tL\tI\t)\t)\t)\t)\t)\t)\t)\tP\tK\tq\t3\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t+\tD\tI\tI\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tJ\t6\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t7\tP\tI\tI\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tD\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t7\tI\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tI\tK\t+\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\to\tP\tI\tI\tI\tI\t)\t)\t)\t)\t)\t)\t)\tI\t)\t(\t(\t_\t_\t_\t_\t_\t(\t_\tJ\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\ty\t)\tI\tI\t)\t)\t)\t)\t)\t)\t)\t)\t!\tl\tf\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t>\t>\t;\t-\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\to\tU\t)\t)\t)\t)\t)\t)\t)\t)\t)\t~\tf\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t=\tR\t)\t)\t)\t)\t)\t)\t)\t)\tk\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tt\tT\t)\t)\t)\t)\t)\t)\t)\tl\t,\t,\t,\t,\tx\tS\t+.-.:.:.:.:.:.:.1.3.2.<.o.B\t,\t,\t,\t,\t,\t,\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tu\t^\t)\t)\t)\t)\t)\t)\tW\t,\t,\t,\tc\tX.0.q.q.q.q.q.q.q.q.u.j.j.j.j.j.f.i.1.N\t,\t,\t,\t,\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t$\tu\t/\t)\t)\t)\t)\t)\t)\t2\t,\t,\tv\t|\t4.q.q.q.q.q.q.q.q.q.g.j.j.j.j.j.j.j.h.e.Z\t,\t,\t,\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t5\tu\t(\t)\t)\t)\t)\t)\t!\t,\t,\t,\t`\t..8.q.q.q.q.q.q.q.q.q.a.j.j.j.j.j.j.j.j.h.6.,\t,\t,\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\te\tu\t/\t)\t)\t)\t)\t)\tE\t,\t,\t,\t....8.q.q.q.q.q.q.q.q.q.w.i.p.s.h.j.j.j.j.h.q.A\t,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\tt\tu\t)\t)\t)\t)\t)\t)\tk\t,\t,\tn\t....5.q.q.q.q.q.q.q.q.q.q.q.q.q.q.r.i.d.f.t.q.O.,\t,\t>\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\ty\tu\t)\t)\t)\t)\t)\t)\tk\t,\t,\tM\t....*.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.%.,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\tu\tu\t)\t)\t)\t)\t)\tI\tk\t,\t,\tM\t......=.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.X.,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t.\t.\t.\t+\t0\tF\tJ\tG\t6\t.\t.\t$\tu\tu\t)\t)\t)\t)\tI\t)\td\t,\t,\tM\t........*.7.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.q.8.]\t,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t.\t.\t3\tL\t)\t)\t)\t)\t7\t.\t.\t*\tu\tu\t)\t)\t)\t)\t)\t)\td\t,\t,\tM\t............*.4.0.q.q.q.q.q.q.q.q.q.q.q.8.,.@.`\t,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t.\t.\tF\t)\t)\t)\t)\t)\t7\t.\t.\t*\tu\tu\t)\t)\t)\t)\t)\t)\tE\t,\t,\tc\t..................&.=.;.>.>.>.>.;.=.*.#.......C\t,\t,\t,\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t.\tL\t)\t)\t)\t)\t)\t3\t.\t.\t=\tu\tu\t(\t)\t)\t)\t)\t)\tQ\t,\t,\t,\t`\t..........................................|\tv\t,\t,\t>\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t.\t)\tT\tU\tp\ti\tU\t&\t.\t.\t=\tu\tu\tI\t)\t)\t)\t)\t)\t(\t,\t,\t,\tv\t|\t......................................}\tb\t,\t,\t,\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t%\tp\tu\tu\tu\tu\tu\t*\t.\t.\tw\tu\tu\t(\tI\t)\t)\t)\t)\t)\th\t,\t,\t,\tv\t`\t................................|\tC\tc\t,\t,\t,\t>\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t=\tu\tu\tu\tu\tu\tu\t$\t.\t.\tw\tu\tu\t(\t)\t)\t)\t)\t)\t)\t_\t1\t,\t,\t,\t,\tM\t`\t}\t....................{\t`\tM\t,\t,\t,\t,\t,\t,\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t5\tu\tu\tu\tu\tu\tu\t$\t.\t.\te\tu\tu\t(\t)\t)\t)\t)\t)\t)\t)\tQ\t1\t,\t,\t,\t,\t,\t,\tc\tm\tM\tV\tV\tV\tV\tM\tn\t,\t,\t,\t,\t,\t,\t,\t,\t;\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t5\tu\tu\tu\tu\tu\tu\t$\t.\t.\te\tu\tu\t/\t)\t)\t)\t)\t)\t)\t)\t)\t!\tg\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t:\tX\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\te\tu\tu\tu\tu\tu\tu\t$\t.\t.\te\tu\tu\t/\t)\t)\t)\t)\t)\t)\t)\t)\tI\t)\tQ\tj\t<\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\t,\tf\td\ts\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\te\tu\tu\tu\tu\tu\tu\t$\t.\t.\te\tu\tu\tT\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t_\t~\tE\tz\tl\tj\th\tl\td\td\tE\tW\t_\t(\tI\t)\tL\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tr\tu\tu\tu\tu\tu\tu\t$\t.\t.\tr\tu\tu\tT\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tL\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tr\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tR\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tL\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tr\tu\tu\tu\tu\tu\tu\t.\t.\t.\tr\tu\tu\tU\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\ty\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\ti\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\ty\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t(\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\ty\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tT\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tT\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tt\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tU\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tY\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tt\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\ti\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\ti\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tr\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tu\tR\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tT\tu\to\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tt\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tu\ti\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tI\ta\tu\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\te\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tu\tu\ta\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tT\tu\ty\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tw\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tu\tu\tu\tU\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t(\tu\tu\ty\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\tw\tu\tu\tu\tu\tu\tu\t.\t.\t.\te\tu\tu\tu\tu\tu\tu\tu\ta\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t/\tp\tu\tu\tr\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData(".\t.\t.\t=\tu\tu\tu\tu\tu\tu\t.\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\ti\tR\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\tT\tu\tu\tu\tu\t5\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t#\tu\tu\tu\tu\tu\tu\t$\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ti\tY\t^\t(\t)\t)\t)\t)\t)\t)\t)\t)\t)\t)\t(\tR\tp\tu\tu\tu\tu\tu\t5\t.\t.\t.\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t.\tu\tu\tu\tu\tu\tu\t$\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tp\tY\tY\tR\tR\tR\tR\tY\ta\ti\tu\tu\tu\tu\tu\tu\tu\tu\t*\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t.\te\tu\tu\tu\tu\tu\t$\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\to\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t.\t.\t.\t*\tu\tu\tu\tu\tu\t$\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t.\t.\t.\te\tu\tu\tu\tu\t$\t.\t.\t=\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t.\t.\t.\t.\t=\tw\tw\tw\t.\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\ty\tu\tu\tu\tu\tr\t.\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t=\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\t*\t.\t.\t#\t*\t*\t5\t5\tw\t=\t*\t*\t.\t#\tt\tu\tu\tu\tu\tw\t.\t.\t.\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t*\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t*\tu\tu\tu\tu\tu\tu\t*\t.\t.\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t*\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t*\tt\ti\tu\tu\tu\tu\tu\tu\to\t.\t.\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t%\tu\tu\tu\tu\tu\ti\tu\tu\tu\tu\tu\ty\t.\t.\t.\t.\t.\t.\t.\t.\ty\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t#\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t.\t.\t.\ty\tu\tu\tu\tu\tu\tu\tu\tu\tu\tr\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t.\t.\t.\ty\tu\tu\tu\tu\tu\tu\tu\tu\tu\t5\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t.\t.\t.\ty\tu\tu\tu\tu\tu\tu\tu\tu\tu\t*\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t.\t.\t.\t\t\t\t\t.\t.\t.\tr\tu\tu\tu\tu\tu\tu\tu\tu\tu\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\ty\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tt\t.\t.\t.\t\t\t\t\t.\t.\t.\tw\tu\tu\tu\tu\tu\tu\tu\tu\tt\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tt\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tr\t.\t.\t.\t\t\t\t\t.\t.\t.\t#\ty\tu\tu\tu\tu\tu\tu\ty\t$\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\tr\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\tr\t.\t.\t.\t\t\t\t\t\t\t.\t.\t.\t#\t=\te\tr\te\tr\t5\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\te\tu\tu\tu\tu\tu\tu\tu\tu\tu\tu\te\t.\t.\t.\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t*\tu\tu\tu\tu\tu\tu\tu\tu\tu\ty\t$\t.\t.\t.\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t5\tr\ty\ty\ty\ty\tr\te\t=\to\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
, info.receiver, PRIVMSG | CHANNEL);
		bot.sendData("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t.\t.\t.\t.\t.\t.\t.\t.\t.\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t", info.receiver, PRIVMSG | CHANNEL);
	}
	else if (info.type & CHANNEL && quoi == "quoi") 
		bot.sendData("coubeh", info.receiver, PRIVMSG | CHANNEL);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return 1;

	Bot	irc("Quoicoubot");

	if (irc.connectBot(argv[1], atoi(argv[2])) == -1)
	{
		std::cout << "Connection failed" << std::endl;
		return 1;
	}

	if (irc.identification(argv[3]) == -1)
	{
		std::cout << "Authentification failed" << std::endl;
		return 1;
	}

	std::string	buffer;
	t_info	info;
	t_cmd	cmd;

	while (irc.getRunning())
	{
		buffer = "";
		if (irc.recvData(buffer) == -1)
			break;
		info = irc.getInfo(buffer);
		cmd = irc.getCmd(buffer);
		std::cout << buffer << std::endl;
		execute(irc, cmd, info);
	}

	irc.disconnectBot();

	return 0;
}
