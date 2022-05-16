/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:38:29 by hyson             #+#    #+#             */
/*   Updated: 2022/05/16 17:14:42 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << YELLOW << "[Show Value]" << EOC << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << sp.getVal(i) << " ";
	std::cout << std::endl;
	std::cout << YELLOW << "[ShortestSpan]" << EOC << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "[LongestSpan]" << EOC << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "[Show No Span Exception]" << EOC << std::endl;
	Span sp1 = Span(10);
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << EOC << std::endl;
	}
	try
	{
		std::cout << RED << sp1.longestSpan() << EOC << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << YELLOW << "[RangeIter - Exception]" << EOC << std::endl;
	std::vector<int> range(15);
	for (int i = 0; i < 15; i++)
		range[i] = i;
	Span test = Span(10);
	try
	{
		test.rangeIter(range.begin(), range.end());
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << EOC << std::endl;
	}

	std::cout << std::endl;
	std::cout << YELLOW << "[Show After Rangeiter Value - Exception]" << EOC << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << test.getVal(i) << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "[RangeIter - special]" << EOC << std::endl;
	Span test2 = Span(10);
	std::vector<int> range1(5);
	range1.push_back(11);
	range1.push_back(12);
	range1.push_back(13);
	range1.push_back(14);
	range1.push_back(15);

	for (int i = 0; i < 10; i++)
		std::cout << range1[i] << " ";
	std::cout << std::endl;
	std::vector<int>::iterator its = range1.begin();
	std::vector<int>::iterator ite = range1.end();

	its++;
	ite--;
	ite--;

	try
	{
		test2.rangeIter(its, ite);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << EOC << std::endl;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "[Show After RangeIter Value - special]" << EOC << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << test2.getVal(i) << " ";
	return 0;
}
