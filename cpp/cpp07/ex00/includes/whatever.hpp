/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:22:31 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 15:28:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define YELLOW		"\033[1;33m"
# define EOC		"\033[0;0m"

template <typename T>
void	swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T		min(T& a, T&b)
{
	return (a < b ? a : b);
}

template <typename T>
T		max(T& a, T& b)
{
	return (a > b ? a : b);
}

#endif
