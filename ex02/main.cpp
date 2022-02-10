/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:22:37 by adidion           #+#    #+#             */
/*   Updated: 2022/02/09 12:10:16 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "Construction:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				CEO("CEO", 1);
	Bureaucrat				Billy("Billy", 142);
	ShrubberyCreationForm	Shrubbery("shrubbery");
	RobotomyRequestForm		Robot("robot");
	PresidentialPardonForm	President("President");
	std::cout << std::endl << std::endl;
	
	std::cout << "Robotomy:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl << "[Not signed yet]" << std::endl;
	CEO.executeForm(Robot);
	Robot.beSigned(CEO);

	std::cout << std::endl << "[Signed (50% failure causing by the random)]" << std::endl;
	CEO.executeForm(Robot);
	std::cout << std::endl;

	std::cout << std::endl << "[GradeTooLowException]" << std::endl;
	Billy.executeForm(Robot);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Shrubbery:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[Not signed yet]" << std::endl;
	CEO.executeForm(Shrubbery);
	Shrubbery.beSigned(CEO);

	std::cout << std::endl << "[Signed]" << std::endl;
	CEO.executeForm(Shrubbery);
	std::cout << std::endl;

	std::cout << std::endl << "[GradeTooLowException]" << std::endl;
	Billy.executeForm(Shrubbery);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Presidential:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[Not signed yet]" << std::endl;
	CEO.executeForm(President);
	President.beSigned(CEO);

	std::cout << std::endl << "[Signed]" << std::endl;
	CEO.executeForm(President);
	std::cout << std::endl;

	std::cout << std::endl << "[GradeTooLowException]" << std::endl;
	Billy.executeForm(President);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "Destruction:" << std::endl;
	std::cout << "----------------------------" << std::endl;
}