/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:06:45 by hyson             #+#    #+#             */
/*   Updated: 2022/09/03 18:15:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

template<typename Category,typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&> //TODO Distance 잘 모르겠음
struct iterator
{
	typedef T			value_type;
    typedef Distance	difference_type;
    typedef Pointer		pointer;
    typedef Reference	reference;
    typedef Category	iterator_category;
};

#endif
