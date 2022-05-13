/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:13:39 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 16:55:30 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data		cadet1(1, "hyson", 1);
	Data		copy_cadet;
	Data		cadet2(cadet1);
	uintptr_t	p;
	Data*		data_ptr;

	copy_cadet = cadet1;

	std::cout << cadet1;
	std::cout << copy_cadet;
	std::cout << cadet2;
	std::cout << std::endl;

	p = serialize(&cadet1);
	data_ptr = deserialize(p);

	std::cout << &cadet1 << std::endl;
	std::cout << data_ptr << std::endl;

	std::cout << cadet1 << std::endl;
	print_state(data_ptr);
	return (0);
}

