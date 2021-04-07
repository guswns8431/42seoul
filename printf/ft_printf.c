/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:55:51 by hyson             #+#    #+#             */
/*   Updated: 2021/04/07 16:08:27 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{

		if (*format == '%')
			len += ft_check_option_type((char **)&format, ap);
		else
		{
			++len;
			write(1, format++, 1);
		}
	}
	return (len);
}
