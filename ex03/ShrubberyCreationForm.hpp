/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:54:02 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 17:44:42 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( const ShrubberyCreationForm &obj );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &obj );
		~ShrubberyCreationForm();
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
		class FailureOfOpen : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif