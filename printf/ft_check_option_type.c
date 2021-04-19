/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:07:54 by hyson             #+#    #+#             */
/*   Updated: 2021/04/18 00:59:32 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_option_type(char **format, va_list ap)
{
	t_option val;
	ft_memset(&val, 0, sizeof(t_option));
	while (!ft_is_type(*format) && **format)
	{
		++*format;
		/*
		if (**format == '%')
		{
			++*format;
			write(1, "%", 1);
			val.len += 1;
		}
		*/
		ft_check_option(&val, format);
	}
	ft_check_type((*format)++, &val, ap);
	return (val.len);
}
