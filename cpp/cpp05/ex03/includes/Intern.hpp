/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:36:05 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 21:12:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		class IsNotExistTypeException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		Intern(void);
		Intern(const Intern& i);
		~Intern(void);
		Intern&	operator=(const Intern& i);

		Form*	makeForm(std::string name, std::string target);
		Form*	shrubbery(std::string name);
		Form*	robot(std::string name);
		Form*	presidential(std::string name);
};

#endif
