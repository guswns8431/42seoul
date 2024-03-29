/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:24:09 by hyson             #+#    #+#             */
/*   Updated: 2022/09/22 18:28:22 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include <cstdint>
# include <stdexcept>

namespace ft
{

/*------------------------------------------------------------------------------*/
/*									E Q U A L									*/
/*------------------------------------------------------------------------------*/
	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
			{
				return (false);
			}
			first1++;
			first2++;
		}
		return (true);
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
			{
				return (false);
			}
			first1++;
			first2++;
		}
		return (true);
	}

/*------------------------------------------------------------------------------*/
/*					L E X I C O G R A P H I C A L _ C O M P A R E				*/
/*------------------------------------------------------------------------------*/
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first2 != last2)
		{
			if (first1 == last1 || *first1 < *first2)
			{
				return (true);
			}
			if (*first1 > *first2)
			{
				return (false);
			}
			first1++;
			first2++;
		}
		return (false);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while (first2 != last2)
		{
			if (first1 == last1 || comp(*first1, *first2))
			{
				return (true);
			}
			if (comp(*first2, *first1))
			{
				return (false);
			}
			first1++;
			first2++;
		}
		return (false);
	}
}

#endif
