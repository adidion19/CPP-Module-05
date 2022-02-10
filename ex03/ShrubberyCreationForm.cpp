/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:53:38 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 16:59:145 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &obj ): Form(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	_target = obj.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
	this->_target = obj.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

const char* ShrubberyCreationForm::FailureOfOpen::what() const throw()
{
	return ("failure of open");
}

void ShrubberyCreationForm::execute(Bureaucrat const & a) const
{

	std::string	tree =
	"     ccee88oo          \n"
	"  C8O8O8Q8PoOb o8oo    \n"
	" dOB69QO8PdUOpugoO9bD  \n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"   6OuU  /p u gcoUodpP \n"
	"      \\\\//  /douUP   \n"
	"        \\\\////       \n"
	"         |||/\\        \n"
	"         |||\\/        \n"
	"         |||||         \n"
	"  .....\\//||||\\....  \n";

	try
	{
		if (!getIsSigned())
		{
			std::cout << this->getName() << " isn't signed yet" << std::endl;
			return ;
		}
		if (a.getGrade() > getGradeToExecute())
			throw (Form::GradeTooLowException());
		if (a.getGrade() < 1)
			throw (Form::GradeTooHighException());
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << a.getName() << " can't execute the form " << getName() << " because his grade is too low" << std::endl;
		return ;
	}
	catch (Form::GradeTooHighException)
	{
		std::cout << a.getName() << " can't execute the form " << getName() << " because his grade is too high" << std::endl;
		return ;
	}
	try
	{
		std::ofstream	out(getTarget() += "_shrubbery");
		if (!out.is_open())
			throw (FailureOfOpen());
		else
			out << tree;
	}
	catch (FailureOfOpen)
	{
		std::cout << "can't create this file" << std::endl;
		return ;
	}
}
