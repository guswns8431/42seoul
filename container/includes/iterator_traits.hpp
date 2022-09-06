/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:57:43 by hyson             #+#    #+#             */
/*   Updated: 2022/09/07 00:36:29 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "iterator.hpp" //TODO random_access_iterator_tag 따로 구현하지말고 iterator 라이브러리에서 쓰는게 나으려나
#include <iterator> //TODO 왜 iterator 태그 구현을 해뒀는데 ft:random_access_iterator_tag로 쓰면 틀릴까, std::distance를 쓰는 과정에서 우리가 ft로 정의한 녀석들과 뭔가 겹치는 느낌일까

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
		typedef std::random_access_iterator_tag iterator_category; //TODO 왜 ft로 구현해뒀는데 안될까
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
  		typedef std::ptrdiff_t difference_type;
	 	typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category; //TODO 왜 ft로 구현해뒀는데 안될까
	};
}

#endif
