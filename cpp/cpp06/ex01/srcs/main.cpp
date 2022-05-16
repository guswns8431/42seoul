/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:13:39 by hyson             #+#    #+#             */
/*   Updated: 2022/05/14 20:25:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data		cadet;
	uintptr_t	p;
	Data*		data_ptr;

	cadet.id_ = 1;
	cadet.name_ = "hyson";
	cadet.grade_ = 1;

	p = serialize(&cadet);
	data_ptr = deserialize(p);

	std::cout << &cadet << std::endl;
	std::cout << data_ptr << std::endl;

	std::cout << cadet << std::endl;
	print_state(data_ptr);
	return (0);
}
