#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
	contactCount = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl << "All contacts have been lost forever..." << std::endl;
}

void	PhoneBook::addContact(std::string firstName,
							  std::string lastName,
							  std::string nickName,
							  std::string phoneNumber,
							  std::string darkestSecret)
{
	if (index > 7)
		index = 0;
	if (contactCount < 8)
		contactCount++;
	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickName(nickName);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);
	index++;
}

static std::string	formatString(std::string str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + '.');
}

void	PhoneBook::listContact(void)
{
	std::cout << "#----------#----------#----------#----------#" << std::endl;
	std::cout << "|   index  |first name| last name| nickname |" << std::endl;
	std::cout << "#----------#----------#----------#----------#" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|" <<  std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatString(contacts[i].getNickName()) << "|" << std::endl;
	}
	std::cout << "#----------#----------#----------#----------#" << std::endl;
}

void	PhoneBook::displayContact(int index)
{
	std::cout << "first name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

// getter(s)
int		PhoneBook::getContactCount(void)	{ return contactCount; }
