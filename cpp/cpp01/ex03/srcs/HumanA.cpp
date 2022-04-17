/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:30:42 by hyson             #+#    #+#             */
/*   Updated: 2022/04/17 16:48:58 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &W) : name_(name) , W(W)
{
	std::cout << YELLOW << this->name_ << EOC << GREEN << " appear" << EOC << " with " << BLUE << W.getType() << EOC << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << YELLOW << this->name_ << EOC << RED << " disappeared" << EOC << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << YELLOW << this->name_ << EOC << " attacks with " << BLUE << this->W.getType() << EOC << std::endl;
}
