/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:49:29 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 08:50:41 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << PURPLE << "WrongAnimal" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa) : type(wa.type)
{
	std::cout << PURPLE << "WrongAnimal" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << PURPLE << "WrongAnimal" << EOC << "is " << RED << "deleted" << EOC << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wa)
{
	this->type = wa.type;
	return (*this);
}

std::string	WrongAnimal::setType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << BPURPLE << "WRONG WRONG WRONG ANIMALLLLLLLL" << EOC << std::endl;
}
