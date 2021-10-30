/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:31:28 by hyson             #+#    #+#             */
/*   Updated: 2020/11/23 20:17:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursion(char *arr, int max_digit, int current_digit, int val)
{
	if (current_digit == max_digit)
	{
		write(1, arr, max_digit);
		if (!(arr[0] == (':' - max_digit) && arr[max_digit - 1] == '9'))
		{
			write(1, ", ", 2);
		}
	}
	else
	{
		while (++val <= 9)
		{
			arr[current_digit] = val + '0';
			ft_recursion(arr, max_digit, current_digit + 1, val);
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_recursion(arr, n, 0, -1);
}
