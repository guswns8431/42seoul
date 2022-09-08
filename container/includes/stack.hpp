/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:38:12 by hyson             #+#    #+#             */
/*   Updated: 2022/09/08 22:46:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

/*--------------------------------------------------------------------------*/
/*				        		S T A C K									*/
/*--------------------------------------------------------------------------*/
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container container_type;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::size_type size_type;
			typedef typename container_type::reference reference;
			typedef typename container_type::const_reference const_reference;

/*--------------------------------------------------------------------------*/
/*				C O N S T R U C T O R _ & _ D E S T R U C T O R				*/
/*--------------------------------------------------------------------------*/
	explicit stack(const container_type& container = container_type()) : c(container) {}
	stack(const stack& s) : c(s.c) {}
	~stack(void) {}

	/* member function for util */
	stack& operator=(const stack& s) {
	if (this != &s) {
	c = s.c;
	}
	return *this;
	}

	/* element access */
	reference top(void) {
	return c.back();
	}
	const_reference top(void) const {
	return c.back();
	}

	/* capacity */
	bool empty(void) const {
	return c.empty();
	}

	size_type size(void) const {
	return c.size();
	}

	/* modifiers */
	void push(const value_type& value) {
	c.push_back(value);
	}
	void pop(void) {
	c.pop_back();
	}

	/* friend non member function for relational operators */
	friend bool operator==(const stack& x, const stack& y) {
	return x.c == y.c;
	}
	friend bool operator!=(const stack& x, const stack& y) {
	return x.c != y.c;
	}
	friend bool operator<(const stack& x, const stack& y) {
	return x.c < y.c;
	}
	friend bool operator<=(const stack& x, const stack& y) {
	return x.c <= y.c;
	}
	friend bool operator>(const stack& x, const stack& y) {
	return x.c > y.c;
	}
	friend bool operator>=(const stack& x, const stack& y) {
	return x.c >= y.c;
	}

	protected:
	container_type c;
	};

}

#endif
