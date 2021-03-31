/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/31 18:02:39 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_p(t_option *val, va_list ap)
{
	int		nbr;
	int		len;

	nbr = va_arg(ap, unsigned long long);
	len = ft_nbrlen(nbr, 16);
	if (val->minus == 1)
	{
		write(1, "0x", 2);
		ft_putnbr_base(nbr, "0123456789abcdef");
		ft_process_width(len + 2, val->width, val->zero, val->dot);
	}
	else
	{
		write(1, "0x", 2);
		ft_process_width(len + 2, val->width, val->zero, val->dot);
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
}
