/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:21:26 by hyson             #+#    #+#             */
/*   Updated: 2022/03/24 23:27:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

#define RED	"\033[0;31m"
#define YELLOW	"\033[1;33m"
#define GREEN	"\033[0;32m"
#define BLUE	"\033[0;34m"
#define EOC	"\033[0;0m"

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
