/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:19:52 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 14:08:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define YELLOW		"\033[1;33m"
# define EOC		"\033[0;0m"

template <typename T>
void	iter(T* addr, int len, void(*f)(const T&))
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
	std::cout << std::endl;
}

template <typename T>
void	add(const T& a)
{
	a += 10;
}

template <>
void	add(std::string a)
{
	a += "10";
}

template <typename T>
void	print(const T& t)
{
	std::cout << t << " ";
}

#endif
