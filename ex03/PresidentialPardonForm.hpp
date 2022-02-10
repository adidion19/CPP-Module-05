/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:19:41 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 15:52:36 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm( const PresidentialPardonForm &obj );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &obj );
		~PresidentialPardonForm();
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

#endif