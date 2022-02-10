/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:40:49 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 14:24:40 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		std::string const _name;
		bool isSigned;
		int	gradeToSign;
		int	gradeToExecute;
	public:
		Form(std::string name, int toSign, int toExecute);
		Form( const Form &obj );
		Form &operator=( const Form &obj );
		~Form();
		std::string const getName() const;
		bool getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool	beSigned(Bureaucrat &a);
		class	GradeTooHighException: public std::exception
		{
			virtual const char * what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			virtual const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &ope, Form &b);

#endif