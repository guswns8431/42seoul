/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/13 17:56:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_u(t_option *val, va_list ap)
{
	unsigned int		nbr;
	int		len;

	nbr = va_arg(ap, unsigned int);
	len = ft_nbrlen(nbr, 10);
	val->len = len;
	if (val->minus == 1)
	{
		ft_process_precision_num(val->precision, len);
		ft_putnbr_base(nbr, "0123456789");
		ft_process_width(len, val->width, val->zero, val->dot);
	}
	else
	{
		ft_process_width(len, val->width, val->zero, val->dot);
		ft_process_precision_num(val->precision, len);
		ft_putnbr_base(nbr, "0123456789");
	}
}
