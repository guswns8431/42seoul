/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:09:43 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 16:58:20 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, R_SIGN_GRADE, R_EXEC_GRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : Form(r)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	this->Form::operator=(r);
	return (*this);
}

void					RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	srand(time(NULL));
	std::cout << "ziiiiiiiiing" << std::endl;
	if (rand() % 2)
		std::cout << YELLOW << getName() << EOC << " has been robotomized successfully." << std::endl;
	else
		std::cout << YELLOW << getName() << EOC << " has been failed." << std::endl;
}
