/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:18:02 by hyson             #+#    #+#             */
/*   Updated: 2022/04/27 14:22:55 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << BLUE << "Cat" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

Cat::Cat(const Cat& c) : type(c.type)
{
	std::cout << BLUE << "Cat" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << BLUE << "Cat" << EOC << "is " << RED << "deleted" << EOC << std::endl;
}

Cat& operator=(const Cat& c)
{
	this->type = c.type;
	return (*this);
}

void makeSound(void)
{
	std::cout << BPURPLE << "Miao Miao Miao" << std::endl;
}
