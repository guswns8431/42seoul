/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 15:59:22 by hyson            ###   ########.fr       */
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

Bureaucrat::Bureaucrat(std::string name, int grade) throw(GradeTooHighException, GradeTooLowException)
{
	this->name_ = name;
	this->grade_ = grade;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
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

Bureaucrat&		operator=(const Bureaucrat& b)
{
	this->name_ = b.name_;
	this->grade_ = b.grade;
	return (*this);
}

void			Bureaucrat::increaseGrade(int grade)
{
	--this->grade_;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

void			Bureaucrat::decreaseGrade(int grade)
{
	++this->grade_;
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

std::string		Bureaucrat::getName(void)
{
	return (this->name_);
}

int				Bureaucrat::getGrade(void)
{
	return (this->grade_);
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	if (b.getGrade() == MIN_GRADE)
		std::cout << YELLOW << b.getName() << EOC << ", bureaucrat grade " << RED << b.getGrade() << EOC;
	else if (b.getGrade() == MAX_GRADE)
		std::cout << YELLOW << b.getName() << EOC << ", bureaucrat grade " << GREEN << b.getGrade() << EOC;
	else
		std::cout << YELLOW << b.getName() << EOC << ", bureaucrat grade " << BLUE << b.getGrade() << EOC;
}
