/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:12 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 19:22:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("hyson", 1);
	Bureaucrat b3(b1);
	Bureaucrat b4;
	Bureaucrat b5("hi", 150);

	b4 = b2;

	std::cout << "[ Check Orthodox Canonical Form ]" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;
	std::cout << std::endl;

	std::cout << "[ Check Constructor Exception]" << std::endl;
	try {
		Bureaucrat ce("a", 0);
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Constructor Error : " << EOC << e.what() << std::endl;
	}
	try {
		Bureaucrat ce("b", 151);
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Constructor Error : " << EOC << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Check Increase/Decrease Grade ]" << std::endl;
	try {
		Bureaucrat idg("c", 2);
		idg.increaseGrade();
		std::cout << idg << std::endl;
		idg.decreaseGrade();
		std::cout << idg << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Check Increase/Decrease Grade with Error ]" << std::endl;
	try {
		Bureaucrat idge("d", 1);
		idge.increaseGrade();
		std::cout << idge << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	try {
		Bureaucrat idge("d", 150);
		idge.decreaseGrade();
		std::cout << idge << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
