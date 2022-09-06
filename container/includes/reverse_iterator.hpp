/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:02:56 by hyson             #+#    #+#             */
/*   Updated: 2022/09/07 00:19:25 by hyson            ###   ########.fr       */
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
			//COMMENT explicit 키워드를 통해서 iterator_type만이 들어오고 다른 녀석이 잘못들어와도 암시적 형변환이 되는 것을 막기 위해
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
			//COMMENT reverse의 경우, end를 처음으로 가리키고 있는데,
			//end의 경우 그 배열의 마지막 다음을 가르키기 때문에 그 전을 가리키기 위해 이런식으로 구현
			reference operator*(void) const
			{
				iterator_type tmp = iterator;
				return (*--tmp);
			}
			//COMMENT 여기서 +는 reverse_iterator에서 오버로딩된 연산자를 사용하게 됨
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

		//COMMENT random_access_iterator에서는 pointer로 받은 반면,
		//Iterator로 쓴 이유는 reverse_iterator에는 우리가 구현한 random_access_iterator가 들어가기 때문에 Iterator로 받음.
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
