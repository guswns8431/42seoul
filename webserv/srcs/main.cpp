/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:21:44 by hyson             #+#    #+#             */
/*   Updated: 2022/08/12 14:21:53 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Engine.hpp"

int main(int argc, char **argv)
{
	try
	{
		Engine e(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	exit(1);
}
