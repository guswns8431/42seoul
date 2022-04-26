/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:19:16 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 16:09:36 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap s1;
	ScavTrap s2(s1);
	ScavTrap s3("hyson");

	s2 = s3;

	std::cout << std::endl;
	std::cout << "[ S1 state(repaired after dead) ]" << std::endl;
	s1.attack("someone1");
	s1.takeDamage(50);
	s1.berepaired(100);
	s1.takeDamage(101);
	s1.berepaired(10);

	std::cout << std::endl;
	std::cout << "[ S2 state(attack after dead) ]" << std::endl;
	s2.guardGate();
	s2.takeDamage(100);
	s2.attack("someone2");

	std::cout << std::endl;
	std::cout << "[ S3 state(attack & repair after spend 10 energy) ]" << std::endl;
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.berepaired(1);
	s3.attack("someone3");
	s3.berepaired(1);
	
	std::cout << std::endl;
	return (0);
}
