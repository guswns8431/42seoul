/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:12 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 15:26:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	std::cout << "[ Check B - OK , F - OK ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 3);
		Form paper("foreveryone", 5, 1);
		
		std::cout << std::endl;
		std::cout << "--Before functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper << std::endl;

		std::cout << std::endl;
		hyson.increaseGrade();
		hyson.decreaseGrade();
		hyson.signForm(paper);
		
		std::cout << std::endl;
		std::cout << "--After functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper << std::endl;
	}
	catch (std::exception &e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	std::cout << "Here" << std::endl;
	std::cout << std::endl;

	std::cout << "[ Check B - Error(create) , F - OK ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 0);
		Form paper("foreveryone", 1, 1);

		std::cout << std::endl;
		std::cout << "--Before functoin--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper << std::endl;

		std::cout << std::endl;
		hyson.increaseGrade();
		hyson.decreaseGrade();
		hyson.signForm(paper);

		std::cout << std::endl;
		std::cout << "--After fucntion--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper << std::endl;
	}
	catch (std::exception &e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Check B - OK , F - OK + Error(grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 1);
		Form paper1("for1", 1, 3);
		Form paper2("for2", 2, 3);

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper1 << std::endl;
		std::cout << paper2 << std::endl;

		std::cout << std::endl;
		hyson.decreaseGrade();
		hyson.signForm(paper1);
		hyson.signForm(paper2);

		std::cout << std::endl;
		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper1 << std::endl;
		std::cout << paper2 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "[ Check B - Error(grade) , F - Error(grade) ]" << std::endl;
	try {
		Bureaucrat hyson("hyson", 1);
		Form paper1("for1", 1, 1);

		std::cout << std::endl;
		std::cout << "--Before function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper1 << std::endl;
		
		std::cout << std::endl;
		hyson.increaseGrade();
		hyson.signForm(paper1);
		hyson.decreaseGrade();
		hyson.signForm(paper1);

		std::cout << std::endl;
		std::cout << "--After function--" << std::endl;
		std::cout << hyson << std::endl;
		std::cout << paper1 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << PURPLE << "Error : " << EOC << e.what() << std::endl;
	}
	return (0);
}
