/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/20 20:41:17 by hyson            ###   ########.fr       */
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
		len = ft_process_precision_num(val->precision, len);
		val->len += len;
		ft_putnbr_base(nbr, "0123456789");
		val->len += ft_process_width(len, val->width, val->zero, val->dot);
	}
	else
	{
		val->len += ft_process_width(len, val->width, val->zero, val->dot);
		val->len += ft_process_precision_num(val->precision, val->len);
		ft_putnbr_base(nbr, "0123456789");
	}
}
