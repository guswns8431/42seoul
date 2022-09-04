/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:06:45 by hyson             #+#    #+#             */
/*   Updated: 2022/09/03 21:03:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
/*------------------------------------------------------------------------------*/
/*								I T E R A T O R									*/
/*------------------------------------------------------------------------------*/

	template<typename Category,typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&> //TODO Distance 잘 모르겠음
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

/*------------------------------------------------------------------------------*/
/*							I T E R A T O R _ T A G								*/
/*------------------------------------------------------------------------------*/

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

}
#endif
