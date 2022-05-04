/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:16:36 by hyson             #+#    #+#             */
/*   Updated: 2022/05/04 21:57:46 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char* ShrubberyCreationForm::FileOpenError::what(void) const throw()
{
	return ("Error : Cannot Open File");
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, SIGN_GRADE, EXEC_GRADE)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : Form(s)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s) 
{
	this->Form::operator=(s);
	return (*this);
}

void			ShrubberyCreationForm::execute(Buraucrat const & executor) const
{
	canExecute(executor);
	std::ofstream output_file;

	output_file.open(this->getName() + "_shrubbery", std::ios::out);
	if (output_file.fail())
		throw FileOpenError();
	output_file << ASCII_ART_TREE;
	out.close();
}
