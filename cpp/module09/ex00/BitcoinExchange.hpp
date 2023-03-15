#pragma once

#include <fstream> // std::ofstreamn
#include <iostream> // std::cout, cin...
#include <map> // std::map
#include <cstdlib> // strtof
#include <cerrno> // ernno
#include <cstring> // strlen...

/* Colors */
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define NC "\033[0m"

bool	openCsv( std::ifstream& dataSetFd, const char* filename );
void	split( const std::string& str, const char delimiter, std::string& left, std::string& right );
bool	check_args( const int& ac );
bool	check_values( const char* right, std::string& left );
