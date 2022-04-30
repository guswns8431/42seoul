/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:18:02 by hyson             #+#    #+#             */
/*   Updated: 2022/04/30 16:53:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : b_(NULL)
{
	this->b_ = new Brain();
	this->type = "Cat";
	std::cout << BLUE << "Cat" << EOC << GREEN << " constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Cat::Cat(std::string brain) : b_(NULL)
{
	this->b_ = new Brain(brain);
	this->type = "Cat";
	std::cout << BLUE << "Cat" << EOC << GREEN << " constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Cat::Cat(const Cat& c) : Animal(c), b_(NULL)
{
	std::cout << BLUE << "Cat" << EOC << YELLOW << " copy constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Cat::~Cat(void)
{
	if (this->b_ != NULL)
		delete this->b_;
	std::cout << BLUE << "Cat" << EOC << " is " << RED << "deleted" << EOC << " : " << BLUE << getType() << EOC << std::endl;
}

Cat& Cat::operator=(const Cat& c)
{
	if (this->b_ != NULL)
	{
		delete this->b_;
		this->b_ = NULL;
	}
	this->b_ = new Brain();
	*this->b_ = *c.b_;
	this->type = c.type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << BPURPLE << "Miao Miao Miao" << EOC << std::endl;
}

Brain*	Cat::getBrain(void)
{
	return (this->b_);
}
