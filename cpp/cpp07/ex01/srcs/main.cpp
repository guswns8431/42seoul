/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:36:26 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 02:42:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Test {
	private:
		int val_;
	public:
		Test(void) : val_(0) {};
		Test(int n) : val_(n) {};

		Test	operator+=(int n)
		{
			Test t(this->val_ += n);

			return (t);
		}
		int	getVal(void) const
		{
			return (this->val_);
		}
		void setVal(int n)
		{
			this->val_ = n;
		}
};

std::ostream&	operator<<(std::ostream& o, Test const& t)
{
	o << t.getVal();
	return (o);
}

int main(void)
{

	int arr_int[5] = {0, 1, 2, 3, 4};

	std::cout << YELLOW << "[ int ]" << EOC << std::endl;
	iter(arr_int, 5, add);
	iter(arr_int, 5, print);

	float arr_float[5] = {0.0, 1.1, 2.2, 3.3, 4.4};

	std::cout << std::endl;
	std::cout << YELLOW << "[ float ]" << EOC << std::endl;
	iter(arr_float, 5, add);
	iter(arr_float, 5, print);

	double arr_double[5] = {0.0, 1.1, 2.2, 3.3, 4.4};

	std::cout << std::endl;
	std::cout << YELLOW << "[ double ]" << EOC << std::endl;
	iter(arr_double, 5, add);
	iter(arr_double, 5, print);

	char ch[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << std::endl;
	std::cout << YELLOW << "[ char ]" << EOC << std::endl;
	iter(ch, 5, add);
	iter(ch, 5, print);

	std::string str[5] = {"0", "1", "2", "3", "4"};

	std::cout << std::endl;
	std::cout << YELLOW << "[ str ]" << EOC << std::endl;
	iter(str, 5, add);
	iter(str, 5, print);

	Test t[5];

	t[0].setVal(1);
	t[1].setVal(2);
	t[2].setVal(3);
	t[3].setVal(4);
	t[4].setVal(5);

	std::cout << std::endl;
	std::cout << YELLOW << "[ class ]" << EOC << std::endl;
	iter(t, 5, add);
	iter(t, 5, print);

	const int arr_const_int[5] = {0, 1, 2, 3, 4};

	std::cout << std::endl;
	std::cout << YELLOW << "[ const ]" << EOC << std::endl;
	std::cout << std::endl;
	iter(arr_const_int, 5, print);

	return (0);
}
