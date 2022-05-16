/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:38:08 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 15:44:31 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::AlreadyStoreException::what(void) const throw()
{
	return ("Already Store");
}

const char* Span::NoSpanException::what(void) const throw()
{
	return ("No Span");
}

Span::Span(void)
{
	this->vec_.reserve(0);
}

Span::Span(unsigned int N)
{
	this->vec_.reserve(N);
}

Span::Span(const Span& s)
{
	*this = s;
}

Span::~Span(void)
{
}

Span&	Span::operator=(const Span& s)
{
	this->vec_.reserve(s.vec_.capacity());
	for (unsigned int i = 0; i < s.vec_.capacity(); i++)
		this->vec_.push_back(s.vec_[i]);
	return (*this);
}

int 	Span::getVal(int i) const
{
	return (this->vec_[i]);
}

void	Span::addNumber(int n)
{
	if (this->vec_.size() == this->vec_.capacity())
		throw AlreadyStoreException();
	this->vec_.push_back(n);
}

unsigned int	Span::shortestSpan(void)
{
	std::vector<int> tmp;
	unsigned int	min;

	if (this->vec_.size() < 2)
		throw NoSpanException();
	tmp = this->vec_;
	std::sort(tmp.begin(), tmp.end());
	min = tmp[1] - tmp[0];
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		if (static_cast<unsigned int>(tmp[i + 1] - tmp[i]) < min)
			min = tmp[i + 1] - tmp[i];
	}
	return (min);
}

unsigned int	Span::longestSpan(void)
{
	if (this->vec_.size() < 2)
		throw NoSpanException();
	return (*(max_element(this->vec_.begin(), this->vec_.end())) - *(min_element(this->vec_.begin(), this->vec_.end())));
}
