/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:27:27 by hyson             #+#    #+#             */
/*   Updated: 2022/04/26 15:25:01 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& s);
		ScavTrap(const std::string name);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap& s);
		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif
