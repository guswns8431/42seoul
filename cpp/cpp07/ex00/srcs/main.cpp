/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:28:30 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 01:37:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Test {
	private:
		int val_;
	public:
		Test(void) : val_(0) {}
		Test(int n) : val_(n) {}
		bool	operator<(Test const &t) const
		{
			return (this->val_ < t.val_);
		}
		bool	operator>(Test const &t) const
		{
			return (this->val_ > t.val_);
		}
		int		getVal() const
		{
			return (this->val_);
		}
};

std::ostream&	operator<<(std::ostream &o, const Test &t)
{
	o << t.getVal();
	return (o);
}

int main(void) {
	int a = 2;
	int b = 3;
	
	std::cout << YELLOW << "[ int ]" << EOC << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << YELLOW << "[ string ]" << EOC << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	Test e(10);
	Test f(11);

	std::cout << YELLOW << "[ class ]" << EOC << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

	const int g = 4;
	const int h = 5;

	std::cout << YELLOW << "[ const ]" << EOC << std::endl;
	std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
	std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;

	return 0;
}

