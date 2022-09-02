/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:57:43 by hyson             #+#    #+#             */
/*   Updated: 2022/09/02 15:09:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

/*------------------------------------------------------------------------------*/
/*						I T E R A T O R _ T R A I T S							*/
/*------------------------------------------------------------------------------*/
namespace ft {

	template <class Iterator>
	struct iterator_traits
	{
  		typedef typename Iterator::difference_type difference_type;
  		typedef typename Iterator::value_type value_type;
 		typedef typename Iterator::pointer pointer;
  		typedef typename Iterator::reference reference;
  		typedef typename Iterator::iterator_category iterator_category;
	};
	template <typename T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
  		typedef std::ptrdiff_t difference_type;
	 	typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

#endif
