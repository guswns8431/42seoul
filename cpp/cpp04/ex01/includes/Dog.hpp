/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:58:22 by hyson             #+#    #+#             */
/*   Updated: 2022/04/29 20:06:12 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* b_;
	public:
		Dog(void);
		Dog(const Dog& d);
		~Dog(void);
		Dog&	operator=(const Dog& d);
		void	makeSound(void) const;
};

#endif
