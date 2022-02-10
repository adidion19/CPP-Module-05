/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:37:45 by adidion           #+#    #+#             */
/*   Updated: 2022/02/09 15:01:03 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern( const Intern &obj )
{
	std::cout << "Intern copy constructor" << std::endl;
	(void) obj;
}

Intern	&Intern::operator=( const Intern &obj )
{
	std::cout << "Intern assignation operator" << std::endl;
	(void) obj;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern default destructor" << std::endl;
}

Form	*cloneShrubbery(std::string target)
{
	Form *a = new ShrubberyCreationForm(target);
	return (a);
}

Form	*clonePresident(std::string target)
{
	Form *a = new PresidentialPardonForm(target);
	return (a);
}

Form	*cloneRobot(std::string target)
{
	Form *a = new RobotomyRequestForm(target);
	return (a);
}

const char* Intern::ExceptionFailure::what() const throw()
{
	return ("Intern Exception");
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *a = NULL;
	Form *(*fct[3])(std::string t) = {cloneRobot, clonePresident, cloneShrubbery};
	std::string msg[3] = {"robotomy request", "presidential request", "shrubbery request"};
	for (int i = 0; i < 3; i++)
	{
		if (msg[i] == name)
			a = fct[i](target);
	}
	try
	{
		if (!a)
			throw (Intern::ExceptionFailure());
		std::cout << "Intern created the " << a->getName() << " form" << std::endl;
	}
	catch (ExceptionFailure)
	{
		std::cout << "Intern has failed to create a Form : fire him !" << std::endl;
		return (NULL);
	}
	return (a);
}
