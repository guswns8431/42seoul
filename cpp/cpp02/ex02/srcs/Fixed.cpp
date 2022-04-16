/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:29:12 by hyson             #+#    #+#             */
/*   Updated: 2022/04/16 21:53:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point_ = 0;
}

Fixed::Fixed(const int value)
{
	this->fixed_point_ = value << this->fractional_bits_;
}

Fixed::Fixed(const float value)
{
	this->fixed_point_ = (int)roundf(value * (1 << this->fractional_bits_));
}

Fixed::Fixed(const Fixed& f)
{
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	this->fixed_point_ = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_ = raw;
}

int 	Fixed::toInt() const 
{
	return (this->getRawBits() >> this->fractional_bits_);
}

float	Fixed::toFloat() const
{
	return ((float)this->getRawBits() / (float)(1 << this->fractional_bits_));
}

bool	Fixed::operator>(const Fixed& f)
{
	return (fixed_point_ > f.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f)
{
	return (fixed_point_ >= f.getRawBits());
}

bool	Fixed::operator<(const Fixed& f)
{
	return (fixed_point_ < f.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f)
{
	return (fixed_point_ <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed& f)
{
	return (fixed_point_ == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f)
{
	return (fixed_point_ != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f)
{
	Fixed res(this->toFloat() + f.toFloat());
	
	return (res);
}

Fixed	Fixed::operator-(const Fixed& f)
{
	Fixed res(this->toFloat() - f.toFloat());

	return (res);
}

Fixed	Fixed::operator*(const Fixed& f)
{
	Fixed res(this->toFloat() * f.toFloat());

	return (res);
}

Fixed	Fixed::operator/(const Fixed& f)
{
	Fixed res(this->toFloat() / f.toFloat());

	return (res);
}

Fixed&	Fixed::operator++(void)
{
	++this->fixed_point_;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	f(*this);

	++this->fixed_point_;
	return (f);
}

Fixed&	Fixed::operator--(void)
{
	--this->fixed_point_;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	f(*this);

	--this->fixed_point_;
	return (f);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed	const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed	const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	o << f.toFloat();
	return (o);
}
