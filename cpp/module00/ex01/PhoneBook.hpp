#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(std::string firstName,
					   std::string lastName,
					   std::string nickName,
					   std::string phoneNumber,
					   std::string darkestSecret);

	void	listContact(void);
	void	displayContact(int index);

	// getter(s)
	int		getContactCount(void);

private:
	Contact contacts[8];
	int		index;
	int		contactCount;
};
