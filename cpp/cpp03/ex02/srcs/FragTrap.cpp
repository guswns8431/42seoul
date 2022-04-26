/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:37:22 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 16:52:51 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
	std::cout << BLUE << this->name_ << EOC << " is created" << GREEN << "(FragTrap default constructor)" << EOC << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f)
{
	std::cout << BLUE << this->name_ << EOC << " is created" << YELLOW << "(FragTrap copy constructor)" << EOC << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
	std::cout << BLUE << this->name_ << EOC << " is created" << CYAN << "(FragTrap string constructor)" << EOC << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << BLUE << this->name_ << EOC << " is deleted" << RED << "(FragTrap destructor)" << EOC << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
	this->name_ = f.name_;
	this->hit_points_ = f.hit_points_;
	this->energy_points_ = f.energy_points_;
	this->attack_damage_ = f.attack_damage_;
	std::cout << BLUE << this->name_ << EOC << " is created" << BLUE << "(FragTrap operator =)" << EOC << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap : " << this->name_ << " high fives guys" << std::endl;
}
