/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:31:42 by hyson             #+#    #+#             */
/*   Updated: 2022/04/29 21:51:39 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define BGREEN		"\033[0;42m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define BPURPLE	"\033[0;45m"
# define EOC		"\033[0;0m"

class	Animal {
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal& a);
		virtual ~Animal(void);
		Animal&	operator=(const Animal& a);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		std::string		getType(void);
};

#endif
