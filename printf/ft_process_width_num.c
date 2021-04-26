/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:03:43 by hyson             #+#    #+#             */
/*   Updated: 2021/04/26 16:26:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_process_width_num(int len, int zero, t_option *val)
{
	int i;
	int rt;

	if (val->width != 0 && len < val->width)
	{
		i = val->width - len;
		rt = i;
		if (zero && !val->dot)
		{
			if (val->negative)
			{
				val->len += write(1, "-", 1);
				val->negative = 0;
			}
			while (i--)
				write(1, "0", 1);
		}
		else
			while (i--)
				write(1, " ", 1);
		return (rt);
	}
	else
		return (0);
}
