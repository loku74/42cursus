#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

// getters
std::string	Contact::getFirstName(void) { return first_name; }

std::string	Contact::getLastName(void) { return last_name; }

std::string	Contact::getNickName(void) { return nick_name; }

std::string	Contact::getPhoneNumber(void) { return phone_number; }

std::string	Contact::getDarkestSecret(void) { return darkest_secret; }

// setters
void		Contact::setFirstName(std::string to_set) { first_name = to_set; }

void		Contact::setLastName(std::string to_set) { last_name = to_set; }

void		Contact::setNickName(std::string to_set) { nick_name = to_set; }

void		Contact::setPhoneNumber(std::string to_set) { phone_number = to_set; }

void		Contact::setDarkestSecret(std::string to_set) { darkest_secret = to_set; }
