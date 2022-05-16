/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:11:01 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 17:40:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

# define RED		"\033[0;31m"
# define YELLOW		"\033[0;33m"
# define EOC		"\033[0;0m"

template <typename T>
typename T::iterator easyfind(T& t, int n)
{
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw std::exception();
	return (it);
}

#endif
