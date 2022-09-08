/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:24:09 by hyson             #+#    #+#             */
/*   Updated: 2022/09/08 21:43:31 by hyson            ###   ########.fr       */
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
		while (first1 != last1) //FIXED for문에서 while문으로 바꿈
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
		while (first1 != last1) //FIXED for문에서 while문으로 바꿈
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
	//COMMENT 두 구간의 대응되는 요소를 차례대로 비교하는데 첫 번째 요소가 두 번째 요소보다 작으면 true를 리턴하고 크면 false를 리턴하며 즉시 종료
	//두 컨테이너의 요소를 사전식 순으로 비교, 두번째 컨테이너의 요소가 더 크면 참
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first2 != last2) //FIXED for문에서 while문으로 바꿈
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
		while (first2 != last2) //FIXED for문에서 while문으로 바꿈
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
