/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:56:49 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 08:53:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << PURPLE << "WrongCat" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wc) : WrongAnimal(wc)
{
	std::cout << PURPLE << "WrongCat" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << PURPLE << "WrongCat" << EOC << "is " << RED << "deleted" << EOC << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wc)
{
	this->type = wc.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << BPURPLE << "WRONG WRONG WRONG Miao Miao Miao" << EOC << std::endl;
}
