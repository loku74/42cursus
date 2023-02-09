#pragma once

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	addContact(std::string firstName,
					   std::string lastName,
					   std::string nickName,
					   std::string phoneNumber,
					   std::string darkestSecret);

	// getter(s)
	int		getContactCount(void);

private:
	Contact contacts[8];
	int		index;
	int		contactCount;
};
