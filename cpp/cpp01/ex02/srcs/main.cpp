/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:57:32 by hyson             #+#    #+#             */
/*   Updated: 2022/03/18 18:04:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of string: " << &str << std::endl;
	std::cout << "Address of PTR: " << stringPTR << std::endl;
	std::cout << "Address of REF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string: " << str << std::endl;
	std::cout << "Value of PTR: " << *stringPTR << std::endl;
	std::cout << "Value of REF: " << stringREF << std::endl;
	return (0);
}
