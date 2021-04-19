/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/16 22:28:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_p(t_option *val, va_list ap)
{
	long long	nbr;
	int			len;

	nbr = va_arg(ap, long long);
	len = ft_nbrlen(nbr, 16);
	val->len += len + 2;
	if (val->minus == 1)
	{
		write(1, "0x", 2);
		ft_putnbr_base(nbr, "0123456789abcdef");
		ft_process_width(len + 2, val->width, val->zero, val->dot);
	}
	else
	{
		ft_process_width(len + 2, val->width, val->zero, val->dot);
		write(1, "0x", 2);
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
}
