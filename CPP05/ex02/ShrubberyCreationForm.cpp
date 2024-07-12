#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
	this->_target= "Default"; 
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery naming constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Shrubbery copy assignment operator called" << std::endl;
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

const char* ShrubberyCreationForm::InvalidFileException::what() const throw()
{
	return "Invalid File!";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignStatus() == true && executor.getGrade() <= this->getExecuteGrade())
	{
		std::string tree = 
        "                      _{/ _{${$/}/}/}__                   \n"
        "                     {/{/$}{/{/$}($}{/$} _                \n"
        "                    {/{/$}{/{/$}($)$}{/{/$} _             \n"
        "                 {${/($}$}{/{/$}$}{/){/$}$} /$}           \n"
        "                {/{/($)/}{${/)$}{$($){/}/}/}/}            \n"
        "               _{${/{/{${/{/($)/}/}/}{$(/}/}/}            \n"
        "              {/{/{${${$(/}{${$/}/}{$}($){$/}$}           \n"
        "              _{${/{${/($)$}/}{/{/{/$}$})$}{/$}           \n"
        "             {/{/{${$(/}{/{${${$/})/}{$($)/}/}$}          \n"
        "              {${$/}($){${${$/}/}($){$/}{$/}/})/}         \n"
        "               {/{${$/}{/{${${$/}/}{${$/}/}$}($)          \n"
        "              {/{${$/}{/){${${$/}/}{${$(/}/}$}/}          \n"
        "               {/{${$/}($){${${$(/}/}{$($)/}/}$}          \n"
        "                 {/({/{${/{${$/}($){$/}/}$}/}($}          \n"
        "                  ($){/{$/}{${$/}/}{${$)/}/}($)           \n"
        "                    {/{/{${$/}{/{${${$($)/}               \n"
        "                     {/{${${$/}/}{${$$}/}                 \n"
        "                      {){/ {$/}{$/} $$}$}                 \n"
        "                      ($)  \\.-'.-/                       \n"
        "                  __...--- |'-.-'| --...__                \n"
        "           _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__      \n"
        "         -\"    ' .  . '    |.'-._| '  . .  '              \n"
        "         .  '-  '    .--'  | '-.'|    .  '  . '           \n"
        "                  ' ..     |'-_.-|                        \n"
        "          .  '  .       _.-|-._ -|-._  .  '  .            \n"
        "                      .'   |'- .-|   '.                   \n"
        "          ..-'   ' .  '.   `-._.-`   .'  '  - .           \n"
        "           .-' '        '-._______.-'     '  .            \n"
        "              .      ~,                                   \n"
		"					.        ||   .    ' '-.            	\n"
		"		        ___________//  \\______________           	\n"
		"	         //    Money trees is the perfect   \\          \n"
		"	        ||     place for shade And that's   ||        	\n"
		"	        ||         jus' how I feel          ||          \n"
		"	         \\_______________________________ //			\n"
		"															\n";

		std::string fName = (_target + "_shrubbery");
		std::ofstream outfile(fName.c_str());
		if (!outfile)
		{
        	throw InvalidFileException();
		}
		outfile << tree;
		outfile.close();
	}
	else
	{
		throw GradeTooLowException();
	}
}