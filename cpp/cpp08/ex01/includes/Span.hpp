/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:37:55 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 22:09:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

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
		

		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		template <typename T>
		void	rangeIter(T a, T b)
		{
			while (a != b)
			{
				if (this->vec_.size() < this->vec_.capacity())
					this->vec_.push_back(*a);
				else
					throw AlreadyStoreException();
				a++;
			}
		}
};

#endif
