#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

// index getter
int PhoneBook::getIndex(void)	{ return index; }
