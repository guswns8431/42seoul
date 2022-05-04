/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:58:57 by hyson             #+#    #+#             */
/*   Updated: 2022/05/04 22:09:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

# define SIGN_GRADE 72
# define EXEC_GRADE 45

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& r);
		
		void			execute(Bureaucrat const & executor) const;
}

#endif
