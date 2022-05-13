/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:20:10 by hyson             #+#    #+#             */
/*   Updated: 2022/05/13 19:49:26 by hyson            ###   ########.fr       */
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

	base = generate();
	identify(base);
	identify(*base);

	identify(a);
	identify(*a);
	identify(b);
	identify(*b);
	identify(c);
	identify(*c);

	delete base;
	delete a;
	delete b;
	delete c;
	return (0);
}
