/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:55:51 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 15:52:04 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	len = ft_strlen(format);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_check_option_type(format, ap);
		else
			write(1, format++, 1);
	}
	return (len);
}
