#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(std::string firstName,
							  std::string lastName,
							  std::string nickName,
							  std::string phoneNumber,
							  std::string darkestSecret)
{
	if (index > 7)
		index = 0;
	if (contactCount > 8)
		contactCount = 8;
	contacts[index].setFirstName(firstName);
	contacts[index].setLastName(lastName);
	contacts[index].setNickName(nickName);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);
	index++;
	contactCount++;
}

// getter(s)
int		PhoneBook::getContactCount(void)	{ return contactCount; }