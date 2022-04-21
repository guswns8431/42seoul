/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:18:19 by hyson             #+#    #+#             */
/*   Updated: 2022/04/21 20:50:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "CLAPTRAP_HPP"
# define "CLAPTRAP_HPP"

# include <iostream>

class ClapTrap {
	private:
		std::string		name_;
		unsigned int	hit_points_;
		unsigned int	energy_points_;
		unsigned int	attack_damage_;
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& c);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& c);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	berepaired(unsigned int amount);
};

#endif
