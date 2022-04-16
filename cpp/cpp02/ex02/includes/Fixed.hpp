/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:49:38 by hyson             #+#    #+#             */
/*   Updated: 2022/04/16 21:51:46 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	fixed_point_;
		static const int fractional_bits_ = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& f);
		Fixed&	operator=(const Fixed& f);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		bool operator>(const Fixed& f);
		bool operator<(const Fixed& f);
		bool operator>=(const Fixed& f);
		bool operator<=(const Fixed& f);
		bool operator==(const Fixed& f);
		bool operator!=(const Fixed& f);

		Fixed operator+(const Fixed& f);
		Fixed operator-(const Fixed& f);
		Fixed operator*(const Fixed& f);
		Fixed operator/(const Fixed& f);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed&	min(Fixed& f1, Fixed& f2);
		static const Fixed &min(Fixed const &f1, Fixed const &f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed &max(Fixed const &f1, Fixed const &f2);
};

std::ostream&	operator<<(std::ostream& o, const Fixed& f);

#endif
