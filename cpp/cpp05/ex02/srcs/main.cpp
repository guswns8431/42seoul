/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:12 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 17:50:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "[ Check B - OK , S - OK ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 2);
		ShrubberyCreationForm scf("scf");

		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf << std::endl;

		std::cout << std::endl;
		hyson.increaseGrade();
		hyson.signForm(scf);
		hyson.executeForm(scf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , S - Error(sign grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 145);
		ShrubberyCreationForm scf1("scf1");
		ShrubberyCreationForm scf2(scf1);

		std::cout << "--Before fucntion--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf2 << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(scf2);
		hyson.executeForm(scf2);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf1 << std::endl;
		std::cout << scf2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , S - Error(execute grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 137);
		ShrubberyCreationForm scf1("scf1");

		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf1 << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(scf1);
		hyson.executeForm(scf1);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << scf1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , R - OK ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 1);
		RobotomyRequestForm rrf("rrf");

		std::cout << "--Before functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(rrf);
		hyson.executeForm(rrf);
		std::cout << std::endl;

		std::cout << "--After functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;
	}
	catch (std::exception &e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , R - Error(sign grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 72);
		RobotomyRequestForm rrf("rrf");

		std::cout << std::endl;
		std::cout << "--Before functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(rrf);
		hyson.executeForm(rrf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , R - Error(execute grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 45);
		RobotomyRequestForm rrf("rrf");

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(rrf);
		hyson.executeForm(rrf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << rrf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , P - OK ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 6);
		PresidentialPardonForm ppf("ppf");

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;

		std::cout << std::endl;
		hyson.increaseGrade();
		hyson.signForm(ppf);
		hyson.executeForm(ppf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , P - Error(sign grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 25);
		PresidentialPardonForm ppf("ppf");

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(ppf);
		hyson.executeForm(ppf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "[ Check B - OK , P - Error(execute grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 5);
		PresidentialPardonForm ppf("ppf");

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(ppf);
		hyson.executeForm(ppf);
		std::cout << std::endl;

		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << ppf << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	return (0);
}
