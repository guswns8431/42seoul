/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:37:18 by hyson             #+#    #+#             */
/*   Updated: 2021/04/18 00:48:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_type(char *c, t_option *val, va_list ap)
{
	if (*c == 'c')
		ft_print_type_c(val, ap);
	else if (*c == 's')
		ft_print_type_s(val, ap);
	else if (*c == 'd' || *c == 'i')
		ft_print_type_d(val, ap);
	else if (*c == 'u')
		ft_print_type_u(val, ap);
	else if (*c == 'x')
		ft_print_type_lowx(val, ap);
	else if (*c == 'X')
		ft_print_type_upx(val, ap);
	else if (*c == 'p')
		ft_print_type_p(val, ap);
	else
		ft_print_percent(val, ap);
		/*
	else
	*/
}
