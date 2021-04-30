/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 16:54:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_process_minus(int i, t_option *val)
{
	if (val->minus == 1)
	{
		write(1, "%", 1);
		while (--i > 0)
			write(1, " ", 1);
	}
	else
	{
		while (--i > 0)
		{
			if (val->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, "%", 1);
	}
}

void		ft_print_percent(t_option *val)
{
	int	i;

	val->len = val->width;
	if (val->width == 0)
	{
		i = 1;
		val->len = 1;
	}
	else
		i = val->width;
	ft_process_minus(i, val);
}
