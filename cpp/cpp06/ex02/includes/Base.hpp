/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:08:59 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 18:33:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>

class	Base {
	public:
		virtual ~Base(void) {};
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
