/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:06:13 by hyson             #+#    #+#             */
/*   Updated: 2022/04/30 18:20:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : b_(NULL)
{
	this->b_ = new Brain();
	this->type = "Dog";
	std::cout << BLUE << "Dog" << EOC << GREEN << " constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Dog::Dog(std::string brain)
{
	this->b_ = new Brain(brain);
	this->type = "Dog";
	std::cout << BLUE << "Dog" << EOC << GREEN << " constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Dog::Dog(const Dog& d) : Animal(d), b_(NULL)
{
	*this = d;
	std::cout << BLUE << "Dog" << EOC << YELLOW << " copy constructor " << EOC << "created" << " : " << BLUE << getType() << EOC << std::endl;
}

Dog::~Dog(void)
{
	if (this->b_ != NULL)
		delete this->b_;
	std::cout << BLUE << "Dog" << EOC << " is " << RED << "deleted" << EOC << " : " << BLUE << getType() << EOC << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
	if (this->b_ != NULL)
	{
		delete this->b_;
		this->b_ = NULL;
	}
	this->b_ = new Brain();
	*this->b_ = *d.b_;
	this->type = d.type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << BPURPLE << "Wall Wall Wall" << EOC << std::endl;
}

Brain*	Dog::getBrain(void)
{
	return (this->b_);
}
