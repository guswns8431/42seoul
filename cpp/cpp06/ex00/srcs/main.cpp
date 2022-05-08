/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:36:25 by hyson             #+#    #+#             */
/*   Updated: 2022/05/08 15:57:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Check Format : ./Convert <INPUT> " << std::endl;
		return (1);
	}
	else
	{
		Convert c(argv[1]);
		c.printChar();
		c.printInt();
		c.printFloat();
		c.printDouble();
		//std::cout << Convert(argv[1]);
	}
	return (0);
}
