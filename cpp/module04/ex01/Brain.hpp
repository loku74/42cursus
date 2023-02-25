#pragma once

#include <iostream>
#include "colors.h"

class Brain
{

public:

	Brain( void );
	Brain( Brain const & toCopy );
	~Brain( void );

	Brain &	operator=( Brain const & toAssign );

protected:

	std::string	ideas[100];

};
