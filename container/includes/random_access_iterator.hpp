/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:55:25 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 18:44:16 by hyson            ###   ########.fr       */
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
			typedef T* iterator_type;

			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

			random_access_iterator(void): i_(ft::nil) {}
			random_access_iterator(T* pointer) : i_(pointer) {}
			template <typename U>
			random_access_iterator(const random_access_iterator<U>& i) : i_(i.base()) {}
			~random_access_iterator(void) {}

/*------------------------------------------------------------------------------*/
/*							M E M B E R _ F U N C T I O N						*/
/*------------------------------------------------------------------------------*/
			template <typename U>
			random_access_iterator& operator=(const random_access_iterator<U>& i)
			{
				i_ = i.base();
				return (*this);
			}
			iterator_type base(void) const
			{
				return i_;
			}
			pointer operator->(void) const
			{
				return i_;
			}
			reference operator*(void) const
			{
				return *i_;
			}
			reference operator[](difference_type n) const
			{
				return i_[n];
			}

			random_access_iterator& operator++(void)
			{
				++i_;
				return (*this);
			}
			random_access_iterator& operator--(void)
			{
				--i_;
				return (*this);
			}
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				++i_;
				return (tmp);
			}
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				--i_;
				return (tmp);
			}
			random_access_iterator operator+(difference_type n) const
			{
				return (random_access_iterator(i_ + n));
			}
			random_access_iterator operator-(difference_type n) const
			{
				return (random_access_iterator(i_ - n));
			}
			random_access_iterator& operator+=(difference_type n)
			{
				i_ += n;
				return (*this);
			}
			random_access_iterator& operator-=(difference_type n)
			{
				i_ -= n;
				return (*this);
			}

		private:
			pointer i_;
	};

/*------------------------------------------------------------------------------*/
/*						N O N _ M E M B E R _ F U N C T I O N					*/
/*------------------------------------------------------------------------------*/
	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& i)
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
