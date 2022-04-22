/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:19:16 by hyson             #+#    #+#             */
/*   Updated: 2022/04/22 20:56:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap C0;
	ClapTrap C1("a");
	ClapTrap C2("b");
	ClapTrap C3(C1);
	ClapTrap C4;

	C4 = C2;

	std::cout << std::endl;
	std::cout << "[ C0 state(default) ]" << std::endl;
	C0.attack("someone1");
	C0.takeDamage(3);
	C0.berepaired(10);

	std::cout << std::endl;
	std::cout << "[ C1 state(C1 is dead after takeDamage) ]" << std::endl;
	C1.attack("someone2");
	C1.takeDamage(11);
	C1.attack("someone2");

	std::cout << std::endl;
	std::cout << "[ C2 state(C2 is dead after takeDamage & repaired) ]" << std::endl;
	C2.takeDamage(11);
	C2.attack("someone3");
	C2.berepaired(21);
	C2.attack("someone4");

	std::cout << std::endl;
	std::cout << "[ C3 state(C3 has not enough energy & not dead) ]" << std::endl;
	C3.attack("someone5");
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(1);
	C3.berepaired(10);
	C3.berepaired(20);
	C3.berepaired(30);
	C3.takeDamage(11);
	C3.attack("someone6");

	std::cout << std::endl;
	std::cout << "[ C4 state(C4 can't repaired over 100) ]" << std::endl;
	C4.berepaired(1000);
	C4.takeDamage(110);
	C4.berepaired(500);
	C4.takeDamage(999999);
	C4.attack("someone7");
	std::cout << std::endl;

	return (0);
}
