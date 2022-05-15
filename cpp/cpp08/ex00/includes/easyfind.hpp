/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:11:01 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 19:29:35 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& t, int n)
{
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw std::exception();
	return (it);
}

#endif
