#include "PhoneBook.hpp"
#include <iostream>

static bool	searchContact(PhoneBook &phoneBook)
{
	if (phoneBook.getContactCount() == 0)
	{
		std::cout << "No contact to display, try to insert some" << std::endl;
		return (true);
	}
}

static bool	checkPhoneNumber(std::string phoneNumber)
{
	int	digitCount = 0;

	for (int i = 0; i < (int)phoneNumber.length(); i++)
	{
		if (std::isdigit(phoneNumber[i]))
			digitCount++;
		else if (phoneNumber[i] == ' ')
			continue ;
		else
			return (false);
	}
	if (digitCount == 10)
		return (true);
	else
		return (false);
}

static bool	addContact(PhoneBook &phoneBook)
{
	std::string	infos[5];
	std::string	inputs[5] = {
			"first name",
			"last name",
			"nick name",
			"phone number",
			"darkest secret"
	};

	for (int i = 0; i < 5; i ++)
	{
		std::cout << inputs[i] << ": ";
		std::getline(std::cin, infos[i]);
		if (std::cin.eof())
			return (false);
		if (infos[i].empty())
			i--;
		else if (i == 3)
		{
			if (!checkPhoneNumber(infos[i]))
			{
				std::cout << "Wrong phone number format (XX XX XX XX XX)" << std::endl;
				i--;
			}

		}
	}
	phoneBook.addContact(infos[0], infos[1], infos[2], infos[3],infos[4]);
	return (true);
}

int main(void)
{
	PhoneBook 	phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Insert a command (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "ADD")
		{
			if (!addContact(phonebook))
				return (1);
		}
		else if (command == "SEARCH")
		{
			if (!searchContact(phonebook))
				return (1);

		}
	}
	return (0);
}
