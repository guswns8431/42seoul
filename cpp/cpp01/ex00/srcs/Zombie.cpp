/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:46:17 by hyson             #+#    #+#             */
/*   Updated: 2022/03/18 15:17:32 by hyson            ###   ########.fr       */
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
Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " is vanished" << std::endl;
}




