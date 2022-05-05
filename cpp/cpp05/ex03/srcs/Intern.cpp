/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:51:58 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 21:43:45 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*	Intern::IsNotExistTypeException::what(void) const throw()
{
	return ("Error : Not Exist Type");
}

Intern::Intern(void)
{
}

Intern::Intern(const Intern& i)
{
	(void)i;
}

Intern::~Intern(void)
{
}

Intern&	Intern::operator=(const Intern& i)
{
	(void)i;

	return (*this);
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	std::string type_name[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	void (Intern::*func[3])(void) = {&Intern::shrubbery, &Intern::robot, &Intern::presidential};

	int index = 0;
	for (int index = 0; index < 3; index++)
	{
		if (type_name[i] == target)
		{
			std::cout << "Intern creates " << target << std::endl;
			(this->*func[i])(target);
		}
	}
	throw IsNotExistTypeException();
}

Form*	Intern::shrubbery(std::string name)
{
	return (new ShrubberyCreationForm(name));
}

Form*	Intern::robot(std::string name)
{
	return (new RobotomyRequestForm(name));
}

Form*	Intern::presidential(std::string name)
{
	return (new PresidentialPardonForm(name));
}
