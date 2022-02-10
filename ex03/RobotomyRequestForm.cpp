/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:19 by adidion           #+#    #+#             */
/*   Updated: 2022/02/09 11:24:53 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &obj ): Form(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	_target = obj.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
	this->_target = obj.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

const char* RobotomyRequestForm::FailureOfRandom::what() const throw()
{
	return ("Robotomy failure of random");
}

void RobotomyRequestForm::execute(Bureaucrat const & a) const
{
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
		std::srand((unsigned int)std::time(NULL));
		int r = std::rand() % 2;
		if (r % 2 == 1)
			throw (FailureOfRandom());
	}
	catch (FailureOfRandom)
	{
		std::cout << getName() << " haven't been executed because of the random" << std::endl;
		return ;
	}
	std::cout << getTarget() << " has been robotomized" << std::endl;
}