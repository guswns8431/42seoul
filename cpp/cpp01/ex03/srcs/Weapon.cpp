/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:30:19 by hyson             #+#    #+#             */
/*   Updated: 2022/03/24 23:27:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
	std::cout << BLUE << type_ << EOC << " is " << GREEN << "created" << EOC << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << BLUE << type_ << EOC << " is " << RED << "broken" << EOC << std::endl;
}


const std::string	&Weapon::getType(void)
{
	return (this->type_);
}

void 	Weapon::setType(std::string type)
{
	this->type_ = type;
}
