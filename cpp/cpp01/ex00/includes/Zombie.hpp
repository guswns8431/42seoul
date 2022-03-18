/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:46:27 by hyson             #+#    #+#             */
/*   Updated: 2022/03/18 14:51:33 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie {
	private:
		std::string name_;
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
