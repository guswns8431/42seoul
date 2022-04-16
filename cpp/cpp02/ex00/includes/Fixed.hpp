/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:49:38 by hyson             #+#    #+#             */
/*   Updated: 2022/04/07 22:11:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	fixed_point_;
		static const int fractional_bits_ = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& f);
		Fixed&	operator=(const Fixed& f);
		~Fixed(void);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
