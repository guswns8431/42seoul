/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:07:54 by hyson             #+#    #+#             */
/*   Updated: 2021/04/03 19:52:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_option_type(char **format, va_list ap)
{
	t_option val;
	ft_memset(&val, 0, sizeof(t_option));
	while (**format)
	{
		ft_check_option(&val, format);
		if (ft_is_type(++*format))
			ft_check_type(*format, &val, ap);
	}
}
