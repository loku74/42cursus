#pragma once

#include <string>
#include <iostream>

class Weapon
{

public:
	Weapon( const std::string& name );
	~Weapon();

	const std::string&	getType( void );
	void				setType( const std::string& to_set );

private:

	std::string	_type;

};