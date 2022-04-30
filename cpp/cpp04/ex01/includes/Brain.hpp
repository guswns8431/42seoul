/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:19:02 by hyson             #+#    #+#             */
/*   Updated: 2022/04/30 16:32:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define BGREEN		"\033[0;42m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define BPURPLE	"\033[0;45m"
# define EOC		"\033[0;0m"

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(std::string thought);
		Brain(const Brain& b);
		~Brain(void);
		Brain&		operator=(const Brain& b);
		void		setIdea(std::string str);
		std::string	getIdea(int i);
};

#endif
