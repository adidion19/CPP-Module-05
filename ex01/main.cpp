/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:22:37 by adidion           #+#    #+#             */
/*   Updated: 2022/02/08 14:29:28 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat   b("Billy", 50);
	Form a ("Contract", 62, 42);
	std::cout << a << std::endl << b << std::endl;
	b.signForm(a);
	a.beSigned(b);
	b.signForm(a);
	std::cout << a;
}