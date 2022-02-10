/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:26:52 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 14:22:48 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		std::string	const _name;
		int _grade;
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat( const Bureaucrat &obj );
		Bureaucrat &operator=( const Bureaucrat &obj );
		~Bureaucrat();
		std::string const &getName() const;
		int	getGrade() const;
		void promote();
		void depromote();
		void signForm(Form &a);
		class	GradeTooHighException: public std::exception
		{
			virtual const char * what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			virtual const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &ope, Bureaucrat &b);

#endif