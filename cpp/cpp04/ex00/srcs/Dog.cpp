/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:06:13 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 20:26:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << BLUE << "Dog" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

Dog::Dog(const Dog& d) : Animal(d)
{
	std::cout << BLUE << "Dog" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << BLUE << "Dog" << EOC << " is " << RED << "deleted" << EOC << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
	this->type = d.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << BPURPLE << "Wall Wall Wall" << EOC << std::endl;
}
