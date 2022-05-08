/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:36:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/08 16:47:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

const char* Convert::CanNotDisplayException::what(void) const throw()
{
	return ("Non displayable");
}

const char* Convert::ImpossibleException::what(void) const throw()
{
	return ("Impossible");
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

	if (isnan(this->value_) || input == "nan" || input == "nanf")
		this->type_ = "NaN";
	else if (isinf(this->value_) || input == "inf" || input == "-inf" || input == "inff" || input == "-inff" || input == "+inf" || input == "+inff")
		this->type_ = "Inf";
	else if ((strlen(pos) == 1 && pos[0] == 'f' && this->value_) || !*pos )
		this->type_ = "Number";
	else if (!*pos && isdigit(*this->input_.end())) //여기서부터 하렴
		this->type_ = "NumberNf";
	else if (strlen(pos) == 1 && isalpha(pos[0]) && this->value_ == 0 && this->input_[0] != '0')
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
	if (this->type_ == "Number")
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
	return (this->value_); //여기도 static_cast를 해야하나?
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
	if (this->value_ > FLT_MAX || this->value_ < FLT_MIN || this->type_ == "NaN" || this->type_ == "Inf")
	{
		std::cout << this->toFloat() << "f" << std::endl;
		return ;
	}
	try {
		if (this->type_ == "NumberNf")
		{
			std::cout << this->toFloat() << "f" << std::endl;
		}
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
		std::cout << this->toDouble() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

/*
std::ostream&	operator<<(std::ostream& o, const Convert& c)
{
	if (c.getError())
	{
		o << "Error";
		return (o);
	}
	c.printChar();
	return (o);
}
*/
