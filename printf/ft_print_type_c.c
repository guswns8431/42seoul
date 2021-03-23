/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/23 15:42:07 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_c(t_option *val, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (val->minus == 1)
	{
		write(1, &c, 1);
		while (--val->width)
			write(1, " ", 1);
	}
	else
	{
		while (--val->width)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}
