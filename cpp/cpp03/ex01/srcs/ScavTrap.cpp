/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:37:22 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 16:08:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	std::cout << BLUE << this->name_ << EOC << " is created" << GREEN << "(ScavTrap default constructor)" << EOC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s)
{
	std::cout << BLUE << this->name_ << EOC << " is created" << YELLOW << "(ScavTrap copy constructor)" << EOC << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	std::cout << BLUE << this->name_ << EOC << " is created" << CYAN << "(ScavTrap string constructor)" << EOC << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << BLUE << this->name_ << EOC << " is deleted" << RED << "(ScavTrap destructor)" << EOC << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	this->name_ = s.name_;
	this->hit_points_ = s.hit_points_;
	this->energy_points_ = s.energy_points_;
	this->attack_damage_ = s.attack_damage_;
	std::cout << BLUE << this->name_ << EOC << " is created" << BLUE << "(ScavTrap operator =)" << EOC << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->hit_points_)
	{
		std::cout << BLUE << "ScavTrap : " << this->name_ << EOC << " is already " << BPURPLE << "dead" << EOC << std::endl;
		return ;
	}
	if (!this->energy_points_)
	{
		std::cout << BLUE << "ScavTrap : " << this->name_ << EOC << " has " << BPURPLE << "not enough energy" << EOC << std::endl;
		return ;
	}
	--this->energy_points_;
	std::cout << BLUE << "ScavTrap : " << this->name_ << EOC << " " << BRED << "attacks" << EOC << " " << target << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap : " << this->name_ << " is in Gate keeper mode" << std::endl;
}
