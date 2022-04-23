/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:31:21 by hyson             #+#    #+#             */
/*   Updated: 2022/04/17 16:50:47 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name) , W(NULL)
{
	std::cout << YELLOW << this->name_ << EOC << GREEN << " appear" << EOC << " with " << BLUE << "hands" << EOC << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << YELLOW << this->name_ << EOC << RED << " disappeared" << EOC << std::endl;
}

void	HumanB::attack(void)
{
	if (!W)
		std::cout << YELLOW << this->name_ << EOC << " attacks with " << BLUE << "hands" << EOC << std::endl;
	else
		std::cout << YELLOW << this->name_ << EOC << " attacks with " << BLUE << this->W->getType() << EOC << std::endl;
}

void	HumanB::setWeapon(Weapon &W)
{
	this->W = &W;
}