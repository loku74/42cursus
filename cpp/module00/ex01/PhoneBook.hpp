#pragma once

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

private:
	Contact contacts[8];
	int		index = 0;
};
