/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:02:57 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 15:59:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define MAX_GRADE 1
# define MIN_GRADE 150

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[0;34m"
# define EOC		"\033[0;0m"

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
