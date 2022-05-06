/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:22:50 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 15:26:32 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat Grade is too high(MAX = 1)");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat Grade is too low(MIN = 150)");
}

Bureaucrat::Bureaucrat(void) : name_("NONAME"), grade_(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name_(name), grade_(grade)
{
	if (this->grade_ > MIN_GRADE)
		throw GradeTooLowException();
	if (this->grade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : name_(b.name_), grade_(b.grade_)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& b)
{
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

const std::string	Bureaucrat::getName(void) const
{
	return (this->name_);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->grade_);
}

void			Bureaucrat::signForm(Form& f)
{
	try {
		f.beSigned(*this);
		std::cout << YELLOW << this->name_ << EOC << " signs " << YELLOW << f.getName() << EOC << std::endl;
	}
	catch (std::exception& e) {
		std::cout << YELLOW << this->name_ << EOC << " couldn't sign " << YELLOW << f.getName() << EOC << " because " << e.what() << std::endl;
	}
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
