/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:37:55 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 17:38:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

# define RED		"\033[0;31m"
# define YELLOW		"\033[0;33m"
# define EOC		"\033[0;0m"

class Span {
	private:
		std::vector<int>	vec_;
	public:
		class AlreadyStoreException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class NoSpanException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		Span(void);
		Span(unsigned int N);
		Span(const Span& s);
		~Span(void);
		Span&	operator=(const Span& s);

		int				getVal(int i) const;
		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		template <typename T>
		void	rangeIter(T begin, T end)
		{
			while (begin != end)
			{
				if (this->vec_.size() >= this->vec_.capacity())
					throw AlreadyStoreException();
				this->vec_.push_back(*begin);
				begin++;
			}
		}
};

#endif
