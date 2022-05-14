/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:36:26 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 14:01:33 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int arr_int[5] = {0, 1, 2, 3, 4};
	float arr_float[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
	double arr_double[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
	char ch[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string str[5] = {"0", "1", "2", "3", "4"};

	std::cout << YELLOW << "[ int ]" << EOC << std::endl;
	iter(arr_int, 5, add);
	iter(arr_int, 5, print);

	std::cout << std::endl;
	std::cout << YELLOW << "[ float ]" << EOC << std::endl;
	iter(arr_float, 5, add);
	iter(arr_float, 5, print);

	std::cout << std::endl;
	std::cout << YELLOW << "[ double ]" << EOC << std::endl;
	iter(arr_double, 5, add);
	iter(arr_double, 5, print);

	std::cout << std::endl;
	std::cout << YELLOW << "[ char ]" << EOC << std::endl;
	iter(ch, 5, add);
	iter(ch, 5, print);

	std::cout << std::endl;
	std::cout << YELLOW << "[ str ]" << EOC << std::endl;
	iter(str, 5, add);
	iter(str, 5, print);

	return (0);
}
