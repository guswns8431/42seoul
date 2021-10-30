/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:36:14 by hyson             #+#    #+#             */
/*   Updated: 2020/11/24 09:53:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int num)
{
	char first_digit;
	char second_digit;

	first_digit = num / 10 + '0';
	second_digit = num % 10 + '0';
	write(1, &first_digit, 1);
	write(1, &second_digit, 1);
}

void	ft_print_comb2(void)
{
	int first_part;
	int second_part;

	first_part = 0;
	while (first_part <= 98)
	{
		second_part = first_part + 1;
		while (second_part <= 99)
		{
			print_num(first_part);
			write(1, " ", 1);
			print_num(second_part);
			if (!(first_part == 98 && second_part == 99))
			{
				write(1, ", ", 2);
			}
			second_part++;
		}
		first_part++;
	}
}
