/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/04/15 21:24:04 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_s(t_option *val, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = "(null)";
		if (val->dot == 1 && val->precision == 0)
			str = "";
	}
	len = ft_strlen(str);
	len = ft_process_precision(len, val->precision);
	val->len = len;
	if (val->minus == 1)
	{
		write(1, str, len);
		ft_process_width(len, val->width, val->zero, val->dot);
	}
	else
	{
		ft_process_width(len, val->width, val->zero, val->dot);
		write(1, str, len);
	}
}
