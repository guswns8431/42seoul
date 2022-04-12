/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:29:12 by hyson             #+#    #+#             */
/*   Updated: 2022/04/12 22:27:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixed_point_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->fixed_point_ = value << this->fractional_bits_;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->fixed_point_ = (int)roundf(value * (1 << this->fractional_bits_));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point_ = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_ = raw;
}

int Fixed::toInt() const 
{
	return (this->getRawBits() >> this->fractional_bits_);
}

float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / (float)(1 << this->fractional_bits_));
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	o << f.toFloat();
	return (o);
}
