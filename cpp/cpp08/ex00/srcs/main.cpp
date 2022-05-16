/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 05:15:15 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 13:48:35 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <deque>
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(14);
	v.push_back(15);

	try
	{
		easyfind(v, 12);
		std::cout << "Success!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}

	try
	{
		easyfind(v, 20);
		std::cout << "Success!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}

	std::deque<char> dq;
	dq.push_back('a');
	dq.push_back('b');
	dq.push_back('c');
	dq.push_back('d');

	try
	{
		easyfind(dq, 'a');
		std::cout << "Success!" << std::endl;
		easyfind(dq, 'e');
	}
	catch(const std::exception& e)
	{
		std::cout << "Not Found" << std::endl;
	}
	return (0);
}
