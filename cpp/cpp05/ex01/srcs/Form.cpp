/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:26:38 by hyson             #+#    #+#             */
/*   Updated: 2022/05/02 16:07:22 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade is too high(MAX = 1)");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade is too low(MIN = 150)");
}

Form::Form(void) : name_("NONAME"), is_signed_(false), sign_grade_(MIN_GRADE), execute_grade_(MIN_GRADE)
{
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade) : name_(name), is_signed_(false), sign_grade_(sign_grade), execute_grade_(execute_grade)
{
	if (this->sign_grade_ > MIN_GRADE || this->execute_grade_ > MIN_GRADE)
		throw GradeTooLowException();
	if (this->sign_grade_ < MAX_GRADE || this->execute_grade_ < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form(const Form& f) : name_(f.getName()), is_signed_(f.getIsSigned()), sign_grade_(f.getSignGrade()), execute_grade_(f.getExecuteGrade())
{
}

Form::~Form(void)
{
}

Form&	Form::operator=(const Form& f)
{
	this->is_signed_ = f.is_signed_;
	return (*this);
}

const std::string	Form::getName(void) const
{
	 return (this->name_);
}

bool				Form::getIsSigned(void) const
{
	return (this->is_signed_);
}

int			Form::getSignGrade(void) const
{
	return (this->sign_grade_);
}

int			Form::getExecuteGrade(void) const
{
	return (this->execute_grade_);
}

void				Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->sign_grade_)
		this->is_signed_ = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& o, const Form& f)
{
	o << YELLOW << f.getName() << EOC << ", sign grade " << BLUE << f.getSignGrade() << EOC << ", exec grade " << BLUE << f.getExecuteGrade() <<  EOC << ", signed " << BLUE << f.getIsSigned() << EOC << std::endl;
	return (o);
}
