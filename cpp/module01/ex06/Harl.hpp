#pragma once

#include <iostream>
#include <string>

enum	e_filter
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{

public:

	Harl();
	~Harl();

	void	complain( std::string level );

private:

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};