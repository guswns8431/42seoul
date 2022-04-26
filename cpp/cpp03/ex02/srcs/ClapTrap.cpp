/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:19:57 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 17:15:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name_ = "Empty";
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_damage_ = 0;
	std::cout << BLUE << this->name_ << EOC << " is created" << GREEN << "(default constructor)" << EOC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) : name_(c.name_), hit_points_(c.hit_points_), energy_points_(c.hit_points_), attack_damage_(c.attack_damage_)
{
	std::cout << BLUE << this->name_ << EOC << " is created" << YELLOW << "(copy constructor)" << EOC << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name_ = name;
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_damage_ = 0;
	std::cout << BLUE << this->name_ << EOC << " is created" << CYAN << "(string constructor)" << EOC << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE << this->name_ << EOC << " is deleted" << RED << "(destructor)" << EOC << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	this->name_ = c.name_;
	this->hit_points_ = c.hit_points_;
	this->energy_points_ = c.energy_points_;
	this->attack_damage_ = c.attack_damage_;
	std::cout << BLUE << this->name_ << EOC << " is created" << BLUE << "(operator =)" << EOC << std::endl;
	return (*this);

}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->hit_points_)
	{
		std::cout << BLUE << this->name_ << EOC << " is already " << BPURPLE << "dead" << EOC << std::endl;
		return ;
	}
	if (!this->energy_points_)
	{
		std::cout << BLUE << this->name_ << EOC << " has " << BPURPLE << "not enough energy" << EOC << std::endl;
		return ;
	}
	--this->energy_points_;
	std::cout << BLUE << this->name_ << EOC << " " << BRED << "attacks" << EOC << " " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > DMMAX)
		amount = DMMAX;
	if (!this->hit_points_)
	{
		std::cout << BLUE << this->name_ << EOC << " is already " << BPURPLE << "dead" << EOC << std::endl;
		return ;
	}
	if (this->hit_points_ <= amount)
		this->hit_points_ = 0;
	else
		this->hit_points_ -= amount;
	std::cout << BLUE << this->name_ << EOC << " takes " << PURPLE << amount << EOC << " damages" << std::endl;
}

void	ClapTrap::berepaired(unsigned int amount)
{
	if (!this->hit_points_)
	{
		std::cout << BLUE << this->name_ << EOC << " is already " << BPURPLE << "dead" << EOC << std::endl;
		return ;
	}
	if (!this->energy_points_)
	{
		std::cout << BLUE << this->name_ << EOC << " has " << BPURPLE << "not enough energy" << EOC << std::endl;
		return ;
	}
	if (this->hit_points_ + amount > HPMAX)
		this->hit_points_ = HPMAX;
	else
		this->hit_points_ += amount;
	--this->energy_points_;
	std::cout << BLUE << this->name_ << EOC << " gets " << BGREEN  << amount << EOC << " hit points" << std::endl;
}
