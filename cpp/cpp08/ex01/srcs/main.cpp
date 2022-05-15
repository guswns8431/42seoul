/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:38:29 by hyson             #+#    #+#             */
/*   Updated: 2022/05/15 22:12:38 by hyson            ###   ########.fr       */
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
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

std::vector<int> range(15, 3);

Span test = Span(10);
test.rangeIter(range.begin(), range.end());
std::cout << test.shortestSpan() << std::endl;

for (int i = 0; i < 10; i++)
	std::cout << test.vec_[i] << std::endl;

return 0;
}
