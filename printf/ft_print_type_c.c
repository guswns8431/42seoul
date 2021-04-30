/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 15:05:35 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_c(t_option *val, va_list ap)
{
	char	c;
	int		i;

	c = va_arg(ap, int);
	val->len = val->width;
	if (val->width == 0)
	{
		i = 1;
		val->len = 1;
	}
	else
		i = val->width;
	if (val->minus == 1)
	{
		write(1, &c, 1);
		while (--i > 0)
			write(1, " ", 1);
	}
	else
	{
		while (--i > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}
