/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:55:25 by hyson             #+#    #+#             */
/*   Updated: 2022/09/04 19:57:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include <iterator>

namespace ft
{

/*--------------------------------------------------------------------------*/
/*				R A N D O M _ A C C E S S _ I T E R A T O R					*/
/*--------------------------------------------------------------------------*/
	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T* iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

			random_access_iterator(void): __i(ft::nil) {} //TODO nil 어떻게 처리할지 고민
			random_access_iterator(T* pointer) : __i(pointer) {}
			template <typename U>
			random_access_iterator(const random_access_iterator<U>& i) : __i(i.base()) {}
			~random_access_iterator(void) {}

			template <typename U>
			random_access_iterator& operator=(const random_access_iterator<U>& i)
			{
				__i = i.base();
				return (*this);
			}
			iterator_type base(void) const { return __i; }
			pointer operator->(void) const { return __i; }
			reference operator*(void) const { return *__i; }
			reference operator[](difference_type n) const { return __i[n]; }

			random_access_iterator& operator++(void)
			{
				++__i;
				return (*this);
			}
			random_access_iterator& operator--(void)
			{
				--__i;
				return (*this);
			}
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				++__i;
				return (tmp);
			}
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				--__i;
				return (tmp);
			}

			random_access_iterator operator+(difference_type n) const //COMMENT iter + n
			{
				return (random_access_iterator(__i + n));
			}
			random_access_iterator operator-(difference_type n) const
			{
				return (random_access_iterator(__i - n));
			}
			random_access_iterator& operator+=(difference_type n)
			{
				__i += n;
				return (*this);
			}
			random_access_iterator& operator-=(difference_type n)
			{
				__i -= n;
				return (*this);
			}

		private:
			pointer __i;
	};

	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& i) //COMMENT n + iter
	{
		return (random_access_iterator<T>(i.base() + n));
	}

	template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() - y.base());
	}

	template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() == y.base());
	}

	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() != y.base());
	}

	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() < y.base());
	}

	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() <= y.base());
	}

	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() > y.base());
	}

	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y)
	{
		return (x.base() >= y.base());
	}

}

#endif