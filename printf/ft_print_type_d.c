/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/28 17:21:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_d(t_option *val, va_list ap)
{
	int		nbr;
	int		len;

	nbr = va_arg(ap, int);
	len = ft_nbrlen(nbr, 10);
	if (val->minus == 1)
	{
		ft_process_precision_num(val->precision, len);
		ft_putnbr(nbr);
		ft_process_width(len, val->width);
	}
	else
	{
		ft_process_width(len, val->width);
		ft_process_precision_num(val->precision, len);
		ft_putnbr(nbr);
	}
}
