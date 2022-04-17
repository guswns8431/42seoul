/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:46:01 by hyson             #+#    #+#             */
/*   Updated: 2022/04/17 16:24:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1 = Zombie();
	Zombie *zombie2 = newZombie("z2");

	zombie1.setName("z1");
	zombie1.announce();
	zombie2->announce();
	randomChump("z3");
	delete zombie2;
	return (0);
}
