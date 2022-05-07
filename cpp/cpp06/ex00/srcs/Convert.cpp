/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:36:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/07 20:16:39 by hyson            ###   ########.fr       */
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
	this->pos_ = NULL;
	this->type_ = "";
	this->error_ = false;
}

Convert::Convert(std::string input)
{
	this->input_ = input;
	this->error_ = false;
	this->value_ = std::strtod(this->input_.c_str(), &(this->pos_));
	try {
		if (this->value_ == 0 && this->input_ != "0")
		{
			if (this->input_.length() >= 2)
				throw ImpossibleException();
			this->type_ = "char";
			this->value_ = this->input_[0];
		}
	}
	catch (std::exception& e) {
		this->error_ = true;
	}
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
	this->pos_ = c.pos_;
	this->type_ = c.type_;
	this->error_ = c.error_;

	return (*this);
}

bool		Convert::getError(void)
{
	return (this->error_);
}

char		Convert::toChar(void)
{
	char ch;

	if (this->error_)
		throw ImpossibleException();
	if (this->type_ == "char")
		ch = static_cast<char>(this->value_);
	else if (!isascii(this->value_))
		throw ImpossibleException();
	else if(!isprint(this->value_))
		throw CanNotDisplayException();
	else
		ch = static_cast<char>(this->value_);
	return (ch);
}

/*
int			Convert::toInt(void)
{
}

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
/*
void		Convert::printInt(void)
{
}

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
