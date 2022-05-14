/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 05:15:15 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 05:25:01 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;

	v.push_back(5);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	std::cout << *v.end() << std::endl;
	std::cout << *easyfind(v, 6) << std::endl;
	return (0);
}
