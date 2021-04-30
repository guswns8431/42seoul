/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 15:19:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_p(t_option *val, va_list ap)
{
	long long	nbr;
	int			len;
	int			tmp;

	len = 0;
	nbr = va_arg(ap, long long);
	tmp = val->width - 2;
	len = ft_nbrlen(nbr, 16);
	val->len += len + 2;
	if (val->minus == 1)
	{
		write(1, "0x", 2);
		if (nbr == 0 && val->precision == 0 && val->dot == 1)
		{
			val->len = 2;
			while (tmp-- > 0)
				val->len += write(1, " ", 1);
			return ;
		}
		ft_putnbr_base(nbr, "0123456789abcdef");
		val->len += ft_process_width_p(len + 2, 0, val);
	}
	else
	{
		if (nbr == 0 && val->precision == 0 && val->dot == 1)
		{
			val->len = 2;
			while (tmp-- > 0)
				val->len += write(1, " ", 1);
			write(1, "0x", 2);
			return ;
		}
		val->len += ft_process_width_p(len + 2, val->zero, val);
		write(1, "0x", 2);
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
}
