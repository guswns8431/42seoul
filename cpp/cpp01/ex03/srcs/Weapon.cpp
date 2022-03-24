/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:30:19 by hyson             #+#    #+#             */
/*   Updated: 2022/03/24 18:46:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

Weapon::~Weapon(void)
{
}


const std::string	&Weapon::getType(void)
{
	return (this->type_);
}

void 	Weapon::setType(std::string type)
{
	this->type_ = type;
}
