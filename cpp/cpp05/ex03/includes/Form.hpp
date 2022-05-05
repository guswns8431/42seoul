/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:57:05 by hyson             #+#    #+#             */
/*   Updated: 2022/05/05 17:00:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define EOC		"\033[0;0m"

class	Bureaucrat;

class	Form {
	private:
		const std::string	name_;
		bool				is_signed_;
		const int			sign_grade_;
		const int			execute_grade_;
	public:
		class	GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class	FormNotSignedException : public std::exception {
			public:
				const char* what(void) const throw();
		};

		Form(void);
		Form(const std::string name, const int sign_grade, const int execute_grade);
		Form(const Form& f);
		~Form(void);
		Form&	operator=(const Form&	f);
		
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		void				beSigned(const Bureaucrat& b);
		void				canExecute(const Bureaucrat& b) const;
		virtual void			execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const Form& f);

#endif
