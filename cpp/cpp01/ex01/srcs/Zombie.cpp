/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:31:08 by hyson             #+#    #+#             */
/*   Updated: 2022/04/17 16:24:53 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->name_ = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << " is vanished" << std::endl;
}
