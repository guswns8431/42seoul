/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:18:19 by hyson             #+#    #+#             */
/*   Updated: 2022/04/23 13:23:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define BRED		"\033[0;41m"
# define GREEN		"\033[0;32m"
# define BGREEN		"\033[0;42m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[0;34m"
# define CYAN		"\033[0;36m"
# define PURPLE		"\033[0;35m"
# define BPURPLE	"\033[0;45m"
# define EOC		"\033[0;0m"

# define HPMAX		100
# define DMMAX		9999

class ClapTrap {
	private:
		std::string		name_;
		unsigned int	hit_points_;
		unsigned int	energy_points_;
		unsigned int	attack_damage_;
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& c);
		ClapTrap(const std::string name);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap& c);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	berepaired(unsigned int amount);
};

#endif
