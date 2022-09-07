/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:55:25 by hyson             #+#    #+#             */
/*   Updated: 2022/09/07 20:19:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include <iterator>

namespace ft
{

/*--------------------------------------------------------------------------*/
/*				R A N D O M _ A C C E S S _ I T E R A T O R					*/
/*--------------------------------------------------------------------------*/
	template <typename T>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			//COMMENT 포인터로 들어올 경우도 처리를 해주기 위해
			//TODO 근데 굳이 왜 T*를 썼을까
			typedef T* iterator_type;

			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

			//TODO nil 어떻게 처리할지 고민
			random_access_iterator(void): __i(ft::nil) {}
			random_access_iterator(T* pointer) : __i(pointer) {}
			template <typename U>
			random_access_iterator(const random_access_iterator<U>& i) : __i(i.base()) {}
			~random_access_iterator(void) {}

/*------------------------------------------------------------------------------*/
/*							M E M B E R _ F U N C T I O N						*/
/*------------------------------------------------------------------------------*/
			template <typename U>
			random_access_iterator& operator=(const random_access_iterator<U>& i)
			{
				__i = i.base();
				return (*this);
			}
			//COMMENT getter느낌으로 생각해도 좋을듯
			iterator_type base(void) const { return __i; }
			pointer operator->(void) const { return __i; }
			reference operator*(void) const { return *__i; }

			//COMMENT difference_type으로 둔 이유는 주소의 시작부터 끝까지
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

/*------------------------------------------------------------------------------*/
/*						N O N _ M E M B E R _ F U N C T I O N					*/
/*------------------------------------------------------------------------------*/
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
