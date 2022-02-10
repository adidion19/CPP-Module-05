/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:40:43 by adidion           #+#    #+#             */
/*   Updated: 2022/02/10 10:21:40 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int toSign, int toExecute): _name(name), gradeToSign(toSign), gradeToExecute(toExecute)
{
	isSigned = 0;
	try
	{
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw (Form::GradeTooLowException());
		if (gradeToSign < 0 || gradeToExecute < 0)
			throw (Form::GradeTooHighException());
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << "Grade too low to be a Form !" << std::endl;
		return ;
	}
	catch (Form::GradeTooHighException)
	{
		std::cout << "Grade too high to be a Form !" << std::endl;
		return ;
	}
	std::cout << "Form default constructor" << std::endl;
}

Form::Form( const Form &obj ): _name(obj.getName()), isSigned(obj.getIsSigned()), gradeToSign(obj.getGradeToSign()), gradeToExecute(obj.getGradeToExecute())
{
	std::cout << "Form copy constructor" << std::endl;
	try
	{
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw (Form::GradeTooLowException());
		if (gradeToSign < 0 || gradeToExecute < 0)
			throw (Form::GradeTooHighException());
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << "Grade too low to be a Form !" << std::endl;
		return ;
	}
	catch (Form::GradeTooHighException)
	{
		std::cout << "Grade too high to be a Form !" << std::endl;
		return ;
	}
	
	*this = obj;
}

Form	&Form::operator=( const Form &obj )
{
	isSigned = obj.getIsSigned();
	gradeToSign = obj.getGradeToSign();
	gradeToExecute = obj.getGradeToExecute();
	return (*this);
}

Form::~Form()
{
	std::cout << "Form default destructor" << std::endl;
}

std::string const Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Too low grade !");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Too high grade !");
}

bool	Form::beSigned(Bureaucrat &a)
{
	try
	{
		if (a.getGrade() > gradeToSign || gradeToSign > 150)
			throw (Form::GradeTooLowException());
		if (a.getGrade() < 1 || gradeToSign < 1)
			throw (Form::GradeTooHighException());
	}
	catch (Form::GradeTooLowException)
	{
		std::cout << "The garde of the Bureaucrat is too low to sign this Form !" << std::endl;
		return (0);
	}
	catch (Form::GradeTooHighException)
	{
		std::cout << "The garde of the Bureaucrat is too high to exist !" << std::endl;
		return (0);
	}
	std::cout << this->getName() << " has been signed by " << a.getName() << std::endl;
	return (isSigned = 1);
}

std::ostream &operator<<(std::ostream &ope, Form &b)
{
	ope << b.getName() << ", Form attributes :" << std::endl << "is signed : " << b.getIsSigned()
	<< std::endl << "Grade to sign : " << b.getGradeToSign() << std::endl << "grade to execute : " << b.getGradeToExecute() << std::endl;
	return (ope);
}
