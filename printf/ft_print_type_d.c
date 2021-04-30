/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 16:58:50 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_max(int pre, int len)
{
	if (pre > len)
		len = pre;
	return (len);
}

static void	ft_process_minus(long long nbr, t_option *val, int len)
{
	if (val->minus == 1)
	{
		if (val->negative)
			val->len += write(1, "-", 1);
		ft_process_precision_num(val->precision, len);
		len = ft_max(val->precision, len);
		val->len += len;
		ft_putnbr_base(nbr, "0123456789");
		val->len += ft_process_width_num(len, 0, val);
	}
	else
	{
		len = ft_max(val->precision, len);
		val->len += len;
		val->len += ft_process_width_num(len, val->zero, val);
		if (val->negative)
			val->len += write(1, "-", 1);
		ft_process_precision_num(val->precision, ft_nbrlen(nbr, 10));
		ft_putnbr_base(nbr, "0123456789");
	}
}

void		ft_print_type_d(t_option *val, va_list ap)
{
	long long	nbr;
	int			len;
	int			tmp;

	len = 0;
	nbr = va_arg(ap, int);
	tmp = val->width;
	if (nbr < 0)
	{
		val->negative = 1;
		nbr *= -1;
		val->width -= 1;
	}
	if (nbr == 0 && val->precision == 0 && val->dot == 1)
	{
		while (tmp--)
			val->len += write(1, " ", 1);
		return ;
	}
	len = ft_nbrlen(nbr, 10);
	ft_process_minus(nbr, val, len);
}
