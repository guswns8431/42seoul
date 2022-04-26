/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:19:16 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 16:53:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap s1;
	FragTrap s2(s1);
	FragTrap s3("hyson");

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
	s2.highFivesGuys();
	s2.takeDamage(100);
	s2.attack("someone2");

	std::cout << std::endl;
	std::cout << "[ S3 state(attack & repair after spend 50 energy) ]" << std::endl;
	for (int i = 0; i < 50; i++)
		s3.berepaired(1);
	s3.attack("someone3");
	s3.berepaired(1);
	
	std::cout << std::endl;
	return (0);
}
