/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:20:10 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 20:06:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base* base;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "[ random ]" << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;

	std::cout << "[ pointer ]" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	std::cout << std::endl;

	std::cout << "[ reference ]" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);

	delete base;
	delete a;
	delete b;
	delete c;
	return (0);
}
