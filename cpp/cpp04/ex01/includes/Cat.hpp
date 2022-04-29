/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:18:10 by hyson             #+#    #+#             */
/*   Updated: 2022/04/29 20:06:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* b_;
	public:
		Cat(void);
		Cat(const Cat& c);
		~Cat(void);
		Cat&	operator=(const Cat& c);
		void	makeSound(void) const;
};

#endif
