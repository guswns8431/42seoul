/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 19:46:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_c(t_option *val, char c)
{
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
