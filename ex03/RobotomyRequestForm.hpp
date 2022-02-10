/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:32:53 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 16:38:39 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( const RobotomyRequestForm &obj );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &obj );
		~RobotomyRequestForm();
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
		class FailureOfRandom : public std::exception
		{
				virtual const char* what() const throw();
		};
};

#endif