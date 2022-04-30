/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:26:48 by hyson             #+#    #+#             */
/*   Updated: 2022/04/30 17:47:35 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << BLUE << "Animal" << EOC << GREEN << " constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Animal::Animal(const Animal& a) : type(a.type)
{
	std::cout << BLUE << "Animal" << EOC << YELLOW << " copy constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Animal::~Animal(void)
{
	std::cout << BLUE << "Animal" << EOC << " is " << RED << "deleted" << EOC << " : " << BLUE << getType() << EOC << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
	this->type = a.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

std::string		Animal::getType(void)
{
	return (this->type);
}
