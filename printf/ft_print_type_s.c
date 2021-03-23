/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:33:55 by hyson             #+#    #+#             */
/*   Updated: 2021/03/23 17:12:54 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_type_s(t_option *val, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	len = ft_strlen(str);
	if (val->minus == 1)
	{
		write(1, str, len);
		//while (--val->width)
		//	write(1, " ", 1);
	}
	else
	{
		//while (--val->width)
		//	write(1, " ", 1);
		write(1, str, len);
	}
}
