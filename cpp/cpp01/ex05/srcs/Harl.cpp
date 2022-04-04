/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:08:57 by hyson             #+#    #+#             */
/*   Updated: 2022/04/04 21:34:55 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << BLUE << "DEBUG" << EOC <<std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << GREEN << "INFO" << EOC << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << YELLOW << "WARNING" << EOC << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << RED << "ERROR" << EOC << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (type[i] == level)
			(this->*func[i])();
}
