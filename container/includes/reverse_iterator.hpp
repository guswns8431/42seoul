/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:02:56 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 18:52:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
/*--------------------------------------------------------------------------*/
/*						R E V E R S E _ I T E R A T O R						*/
/*--------------------------------------------------------------------------*/

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

			reverse_iterator(void) : iterator(iterator_type()) {}
			explicit reverse_iterator(iterator_type i) : iterator(i) {}
			template <class Other>
			reverse_iterator(const reverse_iterator<Other>& i) : iterator(i.base()) {}
			~reverse_iterator(void) {}

/*------------------------------------------------------------------------------*/
/*							M E M B E R _ F U N C T I O N						*/
/*------------------------------------------------------------------------------*/
			template <class Other>
			reverse_iterator& operator=(const reverse_iterator<Other>& i)
			{
				iterator = i.base();
				return (*this);
			}
			iterator_type base(void) const { return iterator; }
			reference operator*(void) const
			{
				iterator_type tmp = iterator;
				return (*--tmp);
			}
			reference operator[](difference_type n) const
			{
				return (*(*this + n));
			}
			pointer operator->(void) const { return &operator*(); }

			reverse_iterator& operator++(void)
			{
				--iterator;
				return (*this);
			}
			reverse_iterator& operator--(void)
			{
				++iterator;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				--iterator;
				return (tmp);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				++iterator;
				return (tmp);
			}

			reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(iterator - n));
			}
			reverse_iterator operator-(difference_type n) const
			{
				return (reverse_iterator(iterator + n));
			}
			reverse_iterator& operator+=(difference_type n)
			{
				iterator -= n;
				return (*this);
			}
			reverse_iterator& operator-=(difference_type n)
			{
				iterator += n;
				return (*this);
			}

		private:
			Iterator iterator;
	};

	/*------------------------------------------------------------------------------*/
	/*						N O N _ M E M B E R _ F U N C T I O N					*/
	/*------------------------------------------------------------------------------*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& i)
	{
		return (reverse_iterator<Iterator>(i.base() - n));
	}

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (y.base() - x.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() == y.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() != y.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() > y.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() >= y.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() < y.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (x.base() <= y.base());
	}

}

#endif
