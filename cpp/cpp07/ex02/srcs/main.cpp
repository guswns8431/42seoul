/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:49:56 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 01:16:14 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 50

class Test {
	private:
		int val_;
	public:
		Test(void) : val_(0) {};
		Test(int n) : val_(n) {};
		int	getVal(void) const
		{
			return (this->val_);
		}
		void setVal(int n)
		{
			this->val_ = n;
		}
};

std::ostream&	operator<<(std::ostream& o, const Test& t)
{
	o << t.getVal();
	return (o);
}
	
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
	{
		std::cout << YELLOW << "[Check copy/assign operator]" << EOC << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		std::cout << PURPLE << "tmp" << EOC << std::endl;
		std::cout << tmp << std::endl;
		std::cout << PURPLE << "test" << EOC << std::endl;
		std::cout << test << std::endl;
	}
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	std::cout << YELLOW << "[Check Out Of Bounds]" << EOC << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << std::endl;
	Array<float> f(4);
	f[0] = 0.0;
	f[1] = 1.1;
	f[2] = 2.2;
	f[3] = 3.3;
	
	std::cout << YELLOW << "[float]" << EOC << std::endl;
	std::cout << f << std::endl;

	std::cout << std::endl;
	Array<double> d(4);
	d[0] = 0.1;
	d[1] = 1.2;
	d[2] = 2.3;
	d[3] = 3.4;

	std::cout << YELLOW << "[double]" << EOC << std::endl;
	std::cout << d << std::endl;

	std::cout << std::endl;
	Array<std::string> str(4);
	str[0] = "I";
	str[1] = "Want To";
	str[2] = "Finish";
	str[3] = "CPP!!";

	std::cout << YELLOW << "[string]" << EOC << std::endl;
	std::cout << RED << str << EOC << std::endl;

	std::cout << std::endl;
	Array<Test> cl(4);
	cl[0].setVal(1);
	cl[1].setVal(2);
	cl[2].setVal(3);
	cl[3].setVal(4);

	std::cout << YELLOW << "[class]" << EOC << std::endl;
	std::cout << cl << std::endl;

	std::cout << std::endl;
	const Array<int> ci(1);

	std::cout << YELLOW << "[const]" << EOC << std::endl;
	std::cout << ci[0] << std::endl;

    delete [] mirror;
    return 0;
}
