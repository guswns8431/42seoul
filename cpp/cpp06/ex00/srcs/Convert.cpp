/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:36:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/08 11:42:37 by hyson            ###   ########.fr       */
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

	if (input == "nan" || input == "nanf")
		this->type_ = "NaN";
	else if (input == "inf" || input == "-inf" || input == "inff" || input == "-inff" || input == "+inf" || input == "+inff")
		this->type_ = "Inf";
	else if (!*pos || (strlen(pos) == 1 && pos[0] == 'f' && isdigit(this->value_)))
		this->type_ = "Number";
	else if (strlen(pos) == 1 && isalpha(pos[0]))
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
	return (static_cast<int>(this->value_));
}

/*
float		Convert::toFloat(void)
{
}

double		Convert::toDouble(void)
{
}

*/
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
		int i;

		i = this->toInt();
		std::cout << i << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

/*
void		Convert::printFloat(void)
{
}

void		Convert::printDouble(void)
{
}

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
