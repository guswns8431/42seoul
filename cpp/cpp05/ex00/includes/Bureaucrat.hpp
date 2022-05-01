/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:02:57 by hyson             #+#    #+#             */
/*   Updated: 2022/05/01 19:31:13 by hyson            ###   ########.fr       */
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
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define EOC		"\033[0;0m"

class	Bureaucrat {
	private:
		const		std::string	name_;
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

		void		increaseGrade(void);
		void		decreaseGrade(void);
		std::string	getName(void) const;
		int			getGrade(void) const;
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b);

#endif
