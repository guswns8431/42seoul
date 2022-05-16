/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:21:34 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 15:07:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << YELLOW << "[Check MutantStack output]" << EOC << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << PURPLE << "Show top" << EOC << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << std::endl;
	std::cout << PURPLE << "After pop & Check size" << EOC << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl;
	std::cout << PURPLE << "Show Stack" << EOC << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << YELLOW << "[Check list output]" << EOC << std::endl;
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	std::cout << PURPLE << "Show back(top)" << EOC << std::endl;
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << PURPLE << "After pop back(top) & Check size" << EOC << std::endl;
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);
	std::list<int>::iterator it1 = l.begin();
	std::list<int>::iterator ite1 = l.end();
	++it1;
	--it1;
	std::cout << std::endl;
	std::cout << PURPLE << "Show list" << EOC << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	return 0;
}
