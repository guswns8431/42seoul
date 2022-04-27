/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:06:13 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 08:52:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << BLUE << "Dog" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

Dog::Dog(const Dog& d) : Animal(d) //잘 돌아가는지 확인,type(d.type)은 왜 안 돌아가지
{
	std::cout << BLUE << "Dog" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << BLUE << "Animal" << EOC << "is " << RED << "deleted" << EOC << std::endl;
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
