/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/22 14:33:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h> //ㅈㅣ워야해

void	ft_print_type_c(t_option *val, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (val->minus == 1)
	{
		write(1, &c, 1);
		// while (--val->width)
		// 	write(1, " ", 1);
	}
	else
	{
		printf("\n%d\n", val->width);
		// while (--val->width)
		// 	write(1, " ", 1);
		write(1, &c, 1);
	}
}
