/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:12 by hyson             #+#    #+#             */
/*   Updated: 2022/05/06 16:43:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	hyson1("hyson1", P_EXEC_GRADE);
	Bureaucrat	hyson2("hyson2", R_EXEC_GRADE);
	Bureaucrat	hyson3("hyson3", S_EXEC_GRADE);
	Intern		intern;

	std::cout << "[ hyson1 ]" << std::endl;
	{
		Form* s = intern.makeForm("paper1", "ShrubberyCreationForm");
		Form* r = intern.makeForm("paper2", "RobotomyRequestForm");
		Form* p = intern.makeForm("paper3", "PresidentialPardonForm");
	
		if (!s | !r | !p)
			return (1);
	
		std::cout << std::endl;
		std::cout << "--Before--" << std::endl;
		std::cout << hyson1 << std::endl;
		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
	
		std::cout << std::endl;
		std::cout << "--hyson1 Sign Form--" << std::endl;
		hyson1.signForm(*s);
		hyson1.signForm(*r);
		hyson1.signForm(*p);

		std::cout << std::endl;
		std::cout << "--hyson1 Execute Form--" << std::endl;
		hyson1.executeForm(*s);
		hyson1.executeForm(*r);
		hyson1.executeForm(*p);

		delete s;
		delete r;
		delete p;
	}

	std::cout << std::endl;
	std::cout << "[ hyson2 ]" << std::endl;
	{
		Form* s = intern.makeForm("paper1", "ShrubberyCreationForm");
		Form* r = intern.makeForm("paper2", "RobotomyRequestForm");
		Form* p = intern.makeForm("paper3", "PresidentialPardonForm");
	
		if (!s | !r | !p)
			return (1);
	
		std::cout << std::endl;
		std::cout << "--Before--" << std::endl;
		std::cout << hyson2 << std::endl;
		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
	
		std::cout << std::endl;
		std::cout << "--hyson2 Sign Form--" << std::endl;
		hyson2.signForm(*s);
		hyson2.signForm(*r);
		hyson2.signForm(*p);

		std::cout << std::endl;
		std::cout << "--hyson2 Execute Form--" << std::endl;
		hyson2.executeForm(*s);
		hyson2.executeForm(*r);
		hyson2.executeForm(*p);

		delete s;
		delete r;
		delete p;
	}

	std::cout << std::endl;
	std::cout << "[ hyson3 ]" << std::endl;
	{
		Form* s = intern.makeForm("paper1", "ShrubberyCreationForm");
		Form* r = intern.makeForm("paper2", "RobotomyRequestForm");
		Form* p = intern.makeForm("paper3", "PresidentialPardonForm");
	
		if (!s | !r | !p)
			return (1);
	
		std::cout << std::endl;
		std::cout << "--Before--" << std::endl;
		std::cout << hyson3 << std::endl;
		std::cout << *s << std::endl;
		std::cout << *r << std::endl;
		std::cout << *p << std::endl;
	
		std::cout << std::endl;
		std::cout << "--hyson3 Sign Form--" << std::endl;
		hyson3.signForm(*s);
		hyson3.signForm(*r);
		hyson3.signForm(*p);

		std::cout << std::endl;
		std::cout << "--hyson3 Execute Form--" << std::endl;
		hyson3.executeForm(*s);
		hyson3.executeForm(*r);
		hyson3.executeForm(*p);

		delete s;
		delete r;
		delete p;
	}
	std::cout << std::endl;

	std::cout << "[ Error ]" << std::endl;
	try {
		intern.makeForm("error", "error");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
