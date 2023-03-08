#include "MutantStack.hpp"
#include <list>

/* colors */
# define YELLOW "\033[1;33m"
# define ORANGE "\033[38;5;208m"
# define NC "\033[0m"

int	main( void )
{
	std::cout << ORANGE << "Mutant stack test:" << NC << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push( 5 );
		mstack.push( 17 );

		std::cout << "mstack.top(): " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack.size(): " << mstack.size() << std::endl;

		mstack.push( 3 );
		mstack.push( 5 );
		mstack.push( 737 );
		mstack.push( 3 );

		std::cout << YELLOW << "Copy of mstack (with copy constructor):" << NC << std::endl;
		MutantStack<int> copy(mstack);
		std::cout << "mstack.top(): " << mstack.top() << std::endl;
		std::cout << "copy.top(): " << copy.top() << std::endl;

		std::cout << YELLOW << "Copy of copy (with assignment operator):" << NC << std::endl;
		MutantStack<int> copyOfCopy;
		copyOfCopy = copy;
		std::cout << "copy.top(): " << copy.top() << std::endl;
		std::cout << "copyOfCopy.top(): " << copyOfCopy.top() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << ORANGE << "std::list test:" << NC << std::endl;
	{
		std::list<int> list;

		list.push_back( 5 );
		list.push_back( 17 );

		std::cout << "list.size(): " << list.size() << std::endl;

		list.push_back( 3 );
		list.push_back( 5 );
		list.push_back( 737 );
		list.push_back( 0 );

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;

		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	return (0);
}