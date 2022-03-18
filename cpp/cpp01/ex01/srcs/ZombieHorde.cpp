/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:32:02 by hyson             #+#    #+#             */
/*   Updated: 2022/03/18 15:45:11 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];
	std::string s = "";

	for (int i = 0; i < N; i++)
	{
		s += "a";
		z[i].setName(name + s);
	}
	return (z);
}
