/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:40:25 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 17:01:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, P_SIGN_GRADE, P_EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p) : Form(p)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& p)
{
	this->Form::operator=(p);
	return (*this);
}

void					PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblerox." << std::endl;
}
