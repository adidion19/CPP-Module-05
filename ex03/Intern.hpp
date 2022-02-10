/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:59 by adidion           #+#    #+#             */
/*   Updated: 2022/02/09 14:51:03 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Form;

class	Intern
{
	public:
		Intern();
		Intern( const Intern &obj );
		Intern &operator=( const Intern &obj );
		~Intern();
		Form *makeForm(std::string form, std::string target);
		class	ExceptionFailure: public std::exception
		{
			virtual const char * what() const throw();
		};
};

#endif