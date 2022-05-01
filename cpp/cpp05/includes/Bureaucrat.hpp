/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:02:57 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 15:21:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Bureaucrat {
	private:
		std::string	name_;
		int			grade_;
	public:
		class	GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& b);
		~Bureaucrat(void);
		Bureaucrat&	operator=(const Bureaucrat&	b);

		void		increaseGrade(int grade);
		void		decreaseGrade(int grade);
		std::string	getName(void);
		int			getGrade(void);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif
