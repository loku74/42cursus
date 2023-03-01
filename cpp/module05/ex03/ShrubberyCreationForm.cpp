#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : Form("ShrubberyCreationForm", 145 , 137), _target(target)
{

}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & toCopy ) : Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute())
{
	*this = toCopy;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & toAssign )
{
	if (this != &toAssign)
	{
		Form::operator=(toAssign);
		_target = toAssign._target;
	}
	return (*this);
}


void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		throw FormNotSignedException();
	}

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream	outfile;

	outfile.open((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cerr << RED << "Couldn't create " << _target + "_shrubbery" << " file." << NC << std::endl;
		return ;
	}

	outfile << "                                            .\n \
                                   .         ;\n \
      .              .              ;%     ;;\n \
        ,           ,                :;%  %;\n \
         :         ;                   :;%;'     .,\n \
,.        %;     %;            ;        %;'    ,;\n \
  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n \
   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n \
    ;%;      %;        ;%;        % ;%;  ,%;'\n \
     `%;.     ;%;     %;'         `;%%;.%;'\n \
      `:;%.    ;%%. %@;        %; ;@%;%'\n \
         `:%;.  :;bd%;          %;@%;'\n \
           `@%:.  :;%.         ;@@%;'\n \
             `@%.  `;@%.      ;@@%;\n \
               `@%%. `@%%    ;@@%;\n \
                 ;@%. :@%%  %@@%;\n \
                   %@bd%%%bd%%:;\n \
                     #@%%%%%:;;\n \
                     %@@%%%::;\n \
                     %@@@%(o);  . '\n \
                     %@@@o%;:(.,'\n \
                 `.. %@@@o%::;\n \
                    `)@@@o%::;\n \
                     %@@(o)::;\n \
                    .%@@@@%::;\n \
                    ;%@@@@%::;.\n \
                   ;%@@@@%%:;;;.\n \
               ...;%@@@@@%%:;;;;,.." << std::endl;

	outfile.close();
}
