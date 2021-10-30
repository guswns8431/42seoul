/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:27:39 by hyson             #+#    #+#             */
/*   Updated: 2020/11/23 10:51:00 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char digit[3];

	digit[0] = '0';
	while (digit[0] <= '7')
	{
		digit[1] = digit[0] + 1;
		while (digit[1] <= '8')
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{
				write(1, &digit[0], 1);
				write(1, &digit[1], 1);
				write(1, &digit[2], 1);
				if (!(digit[0] == '7' && digit[1] == '8' && digit[2] == '9'))
				{
					write(1, ", ", 2);
				}
				digit[2]++;
			}
			digit[1]++;
		}
		digit[0]++;
	}
}
