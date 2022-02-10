/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:16:56 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 17:49:43 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &obj ): Form(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	_target = obj.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & obj)
{
	this->_target = obj.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & a) const
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
	std::cout << getTarget() << " was pardonned by Zaphod Beeblebrox" << std::endl;
}
