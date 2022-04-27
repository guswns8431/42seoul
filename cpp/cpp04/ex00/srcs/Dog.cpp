/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:06:13 by hyson             #+#    #+#             */
/*   Updated: 2022/04/27 14:17:55 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << BLUE << "Dog" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

Dog::Dog(const Dog& d) : type(d.type)
{
	std::cout << BLUE << "Dog" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << BLUE << "Animal" << EOC << "is " << RED << "deleted" << EOC << std::endl;
}

Dog& operator=(const Dog& d)
{
	this->type = d.type;
	return (*this);
}

void makeSound(void)
{
	std::cout << BPURPLE << "Wall Wall Wall" << EOC << std::endl;
}
