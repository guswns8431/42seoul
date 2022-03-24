/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:21:26 by hyson             #+#    #+#             */
/*   Updated: 2022/03/24 18:46:04 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon {
	private:
		std::string type_;
	public:
		Weapon(std::string weapon);
		~Weapon(void);
		const std::string &getType(void);
		void setType(std::string type);
};

#endif
