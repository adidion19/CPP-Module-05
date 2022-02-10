/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <adidion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:22:37 by adidion           #+#    #+#             */
/*   Updated: 2022/02/07 15:34:58 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("billy", 6);
	Bureaucrat b("billyLow", 155);
	Bureaucrat c("billyHigh", 0);
	Bureaucrat d("billyToBePromote", 1);
	Bureaucrat e("billyToBeFired", 150);
	d.promote();
	e.depromote();
	a.promote();
	std::cout << d << std::endl << e << std::endl << a << std::endl;
	a.depromote();
	std::cout << a << std::endl;
}