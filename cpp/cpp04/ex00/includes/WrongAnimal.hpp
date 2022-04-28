/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:43:45 by hyson             #+#    #+#             */
/*   Updated: 2022/04/28 20:52:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define BGREEN		"\033[0;42m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define BPURPLE	"\033[0;45m"
# define EOC		"\033[0;0m"

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wa);
		virtual	~WrongAnimal(void);
		WrongAnimal&	operator=(const WrongAnimal& wa);
		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
