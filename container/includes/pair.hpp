/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:08:50 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 18:39:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

/*------------------------------------------------------------------------------*/
/*									P A I R										*/
/*------------------------------------------------------------------------------*/

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(void) : first(first_type()), second(second_type()) {}
		pair(const first_type& x, const second_type& y) : first(x), second(y) {}
		template <typename U1, typename U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

		pair& operator=(const pair& p)
		{
			if (this != &p)
			{
				first = p.first;
				second = p.second;
			}
			return *this;
		}
	};

/*------------------------------------------------------------------------------*/
/*								M A K E _ P A I R								*/
/*------------------------------------------------------------------------------*/

	template <typename T1, typename T2>
	ft::pair <T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

/*------------------------------------------------------------------------------*/
/*						N O N _ M E M B E R _ F U N C T I O N					*/
/*------------------------------------------------------------------------------*/

	template <typename T1, typename T2>
	bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return (x.first == y.first && x.second == y.second);
	}

	template <typename T1, typename T2>
	bool operator!=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return !(x == y);
	}

	template <typename T1, typename T2>
	bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return (x.first < y.first || (!(x.first > y.first) && x.second < y.second));
	}

	template <typename T1, typename T2>
	bool operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return !(y < x);
	}

	template <typename T1, typename T2>
	bool operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return (y < x);
	}

	template <typename T1, typename T2>
	bool operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return !(x < y);
	}

}

#endif
