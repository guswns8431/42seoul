/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:38:12 by hyson             #+#    #+#             */
/*   Updated: 2022/09/21 14:54:07 by hyson            ###   ########.fr       */
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

/*--------------------------------------------------------------------------*/
/*						M E M B E R _ F U N C T I O N						*/
/*--------------------------------------------------------------------------*/
			stack& operator=(const stack& s)
			{
				if (this != &s)
				{
					c = s.c;
				}
				return (*this);
			}

/*--------------------------------------------------------------------------*/
/*						E L E M E N T _ A C C E S S							*/
/*--------------------------------------------------------------------------*/
			reference top(void)
			{
				return (c.back());
			}
			const_reference top(void) const
			{
				return (c.back());
			}

/*--------------------------------------------------------------------------*/
/*								C A P A C I T Y								*/
/*--------------------------------------------------------------------------*/
			bool empty(void) const
			{
				return (c.empty());
			}

			size_type size(void) const
			{
				return (c.size());
			}

/*--------------------------------------------------------------------------*/
/*							M O D I F I E R	S								*/
/*--------------------------------------------------------------------------*/
			void push(const value_type& value)
			{
				c.push_back(value);
			}
			void pop(void)
			{
				c.pop_back();
			}

		protected:
			container_type c;

	//COMMENT c가 protected라서 그것을 쓸 수 있게 하기 위하여 friend 키워드 사용
	//COMMENT non member function이라고 cppreference에 명시되어 있어서 friend를 통해서 접근가능
		template < class U, class Cn >
		friend bool operator== (const stack< U,Cn >& x, const stack< U,Cn >& y);
		template < class U, class Cn >
		friend bool operator<  (const stack< U,Cn >& x, const stack< U,Cn >& y);

	};

/*--------------------------------------------------------------------------*/
/*					N O N _ M E M B E R _ F U N C T I O N S					*/
/*--------------------------------------------------------------------------*/
	template <class U, class Cn>
	bool operator== (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return (x.c == y.c);
	}
	template <class U, class Cn>
	bool operator<  (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return (x.c < y.c);
	}
	template <class U, class Cn>
	bool operator!= (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return !(x == y);
	}
	template <class U, class Cn>
	bool operator<= (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return !(y < x);
	}
	template <class U, class Cn>
	bool operator>  (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return (y < x);
	}
	template <class U, class Cn>
	bool operator>= (const stack<U,Cn>& x, const stack<U,Cn>& y)
	{
		return !(x < y);
	}

}

#endif
