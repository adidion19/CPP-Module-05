/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:45:09 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 14:27:13 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
	try
	{
		if (_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		if (_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (GradeTooHighException)
	{
		std::cout << "GradeTooHighException thrown on " << *this << std::endl;
	}
	catch (GradeTooLowException)
	{
		std::cout << "GradeTooLowException thrown on " << *this << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat &obj ): _name(obj.getName()), _grade(obj.getGrade())
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	try
	{
		if (_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		if (_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
	}
	catch (GradeTooHighException)
	{
		std::cout << "GradeTooHighException thrown on " << *this << std::endl;
	}
	catch (GradeTooLowException)
	{
		std::cout << "GradeTooLowException thrown on " << *this << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &obj )
{
	_grade = obj.getGrade();
	std::cout << "Bureaucrat assignation operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default destructor" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::promote()
{
	try
	{
		if (_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		if (_grade <= 1)
			throw (Bureaucrat::GradeTooHighException());
		_grade--;
	}
	catch (GradeTooHighException)
	{
		std::cout << "GradeTooHighException thrown on " << *this << std::endl;
	}
	catch (GradeTooLowException)
	{
		std::cout << "GradeTooLowException thrown on " << *this << std::endl;
	}
}

void	Bureaucrat::depromote()
{
	try
	{
		if (_grade >= 150)
			throw (Bureaucrat::GradeTooLowException());
		if (_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		_grade++;
	}
	catch (GradeTooHighException)
	{
		std::cout << "GradeTooHighException thrown on " << *this << std::endl;
	}
	catch (GradeTooLowException)
	{
		std::cout << "GradeTooLowException thrown on " << *this << std::endl;
	}
}

std::ostream &operator<<(std::ostream &ope, Bureaucrat &b)
{
	ope << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (ope);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Too low grade !");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Too high grade !");
}

void Bureaucrat::signForm(Form &a)
{
	try
	{
		if (a.getIsSigned() == 0)
		{
			if (a.getGradeToSign() < this->_grade)
				throw (Bureaucrat::GradeTooLowException());
			if (this->_grade < 1)
				throw (Bureaucrat::GradeTooHighException());
			std::cout << this->_name << " couldn't sign " << a.getName() << " beacause it isn't signed" << std::endl;
			return ;
		}
	}
	catch (Bureaucrat::GradeTooLowException)
	{
		std::cout << this->_name << " couldn't sign " << a.getName() << " beacause grade is too low" << std::endl;
		return ;
	}
	catch (Bureaucrat::GradeTooHighException())
	{
		std::cout << this->_name << " couldn't sign " << a.getName() << " beacause grade is too high" << std::endl;
		return ;
	}
	std::cout << this->_name << " signed " << a.getName() << std::endl;;
}