/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 17:11:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high(MAX = 1)");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low(MIN = 150)");
}

Bureaucrat::Bureaucrat(void)
{
	this->name_ = "NONAME";
	this->grade_ = MIN_GRADE;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name_ = name;
	this->grade_ = grade;
	if (this->grade_ > MIN_GRADE)
		throw GradeTooLowException();
	if (this->grade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
{
	this->name_ = b.name_;
	this->grade_ = b.grade_;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& b)
{
	this->name_ = b.name_;
	this->grade_ = b.grade_;
	return (*this);
}

void			Bureaucrat::increaseGrade(void)
{
	if (this->grade_ - 1 < MAX_GRADE)
		throw GradeTooHighException();
	--this->grade_;
}

void			Bureaucrat::decreaseGrade(void)
{
	if (this->grade_ + 1> MIN_GRADE)
		throw GradeTooLowException();
	++this->grade_;
}

std::string		Bureaucrat::getName(void) const
{
	return (this->name_);
}

int				Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	if (b.getGrade() == MIN_GRADE)
		o << YELLOW << b.getName() << EOC << ", bureaucrat grade " << RED << b.getGrade() << EOC;
	else if (b.getGrade() == MAX_GRADE)
		o << YELLOW << b.getName() << EOC << ", bureaucrat grade " << GREEN << b.getGrade() << EOC;
	else
		o << YELLOW << b.getName() << EOC << ", bureaucrat grade " << BLUE << b.getGrade() << EOC;
	return (o);
}
