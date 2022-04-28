/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:44:50 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 22:09:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "thought";
	std::cout << BLUE << "Brain" << EOC << GREEN << " constructor " << EOC << "created" << std::endl;
}

Brain::Brain(const Brain&b b)
{
	*this = b;
	std::cout << BLUE << "Brain" << EOC << YELLOW << " copy constructor " << EOC << "created" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << BLUE << "Brain" << EOC << " is " << RED << "deleted" << EOC << std::endl;
}

Brain&	Brain::operator=(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	return (*this);
}
