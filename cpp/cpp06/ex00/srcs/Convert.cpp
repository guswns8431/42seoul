/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:36:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 13:48:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

const char* Convert::CanNotDisplayException::what(void) const throw()
{
	return ("Non displayable");
}

const char* Convert::ImpossibleException::what(void) const throw()
{
	return ("impossible");
}

Convert::Convert(void)
{
	this->input_ = "";
	this->value_ = 0;
	this->type_ = "";
}

Convert::Convert(std::string input)
{
	char* pos = NULL;

	this->input_ = input;
	this->value_ = std::strtod(this->input_.c_str(), &pos);

	if (input == "nan" || input == "nanf")
		this->type_ = "NaN";
	else if (input == "inf" || input == "-inf" || input == "inff" || input == "-inff" || input == "+inf" || input == "+inff")
		this->type_ = "Inf";
	else if ((strlen(pos) == 1 && pos[0] == 'f' && this->value_) || !*pos )
		this->type_ = "Number";
	else if (strlen(pos) == 1 && isascii(pos[0]) && this->value_ == 0 && this->input_[0] != '0')
		this->type_ = "Char";
	else
		this->type_ = "Error";
}

Convert::Convert(const Convert& c)
{
	*this = c;
}

Convert::~Convert(void)
{
}

Convert&	Convert::operator=(const Convert& c)
{
	this->input_ = c.input_;
	this->value_ = c.value_;
	this->type_ = c.type_;

	return (*this);
}

char		Convert::toChar(void)
{
	if ((this->value_ - static_cast<int>(this->value_) > 0) || (static_cast<int>(this->value_) - this->value_ > 0))
		throw ImpossibleException();
	else if (this->type_ == "Number")
	{
		if (isascii(this->value_))
		{
			if (!isprint(this->value_))
				throw CanNotDisplayException();
		}
		else
			throw ImpossibleException();
	}
	else if (this->type_ == "Error" || this->type_ == "NaN" || this->type_ == "Inf")
		throw ImpossibleException();
	else if (this->type_ == "Char")
		this->value_ = this->input_[0];
	return (static_cast<char>(this->value_));
}

int			Convert::toInt(void)
{
	if (this->value_ > 2147483647 || this->value_ < -2147483648)
		throw ImpossibleException();
	else if (this->type_ == "Error" || this->type_ == "NaN" || this->type_ == "Inf")
		throw ImpossibleException();
	return (static_cast<int>(this->value_));
}

float		Convert::toFloat(void)
{
	if (this->type_ == "Error")
		throw ImpossibleException();
	return (static_cast<float>(this->value_));
}


double		Convert::toDouble(void)
{
	if (this->type_ == "Error")
		throw ImpossibleException();
	return (static_cast<double>(this->value_));
}

void		Convert::printChar(void)
{
	std::cout << "char : ";
	try {
		char ch;

		ch = this->toChar();
		std::cout << "'" << ch << "'" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
		
}

void		Convert::printInt(void)
{
	std::cout << "int : ";
	try {
		std::cout << this->toInt() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void		Convert::printFloat(void)
{
	std::cout << "float : ";
	try {
		if (this->value_ > FLT_MAX || this->value_ < (-1) * FLT_MAX || this->type_ == "NaN" || this->type_ == "Inf")
			std::cout << this->toFloat() << "f" << std::endl;
		else if (this->value_ - static_cast<int>(this->value_) > 0)
			std::cout << this->toFloat() << "f" << std::endl;
		else if (static_cast<int>(this->value_) - this->value_ > 0)
			std::cout << this->toFloat() << "f" << std::endl;
		else
			std::cout << this->toFloat() << ".0f" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void		Convert::printDouble(void)
{
	std::cout << "double : ";
	try {
		if (this->type_ == "NaN" || this->type_ == "Inf")
			std::cout << this->toDouble() << std::endl;
		else if (this->value_ - static_cast<int>(this->value_) > 0)
			std::cout << this->toDouble() << std::endl;
		else if (static_cast<int>(this->value_) - this->value_ > 0)
			std::cout << this->toDouble() << std::endl;
		else
			std::cout << this->toDouble() << ".0" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
