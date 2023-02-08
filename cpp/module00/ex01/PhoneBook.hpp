#pragma once

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	// index getter
	int	getIndex(void);

private:
	Contact contacts[8];
	int		index;
};
