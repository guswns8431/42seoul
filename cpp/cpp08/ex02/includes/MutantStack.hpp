/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:55:12 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 17:32:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;35m"
# define EOC		"\033[0;0m"

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void) {};
		MutantStack(const MutantStack& m) : std::stack<T>(m) {};
		~MutantStack(void) {};
		MutantStack&	operator=(const MutantStack& m) {
			std::stack<T>::operator=(m);
			return (*this);
		};
		iterator	begin(void) {
			return (this->c.begin());
		};
		iterator	end(void) {
			return (this->c.end());
		};
};

#endif
