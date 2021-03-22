/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:37:18 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 22:27:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_type(char *c, t_option *val, va_list ap)
{
	if (*c == 'c')
	{
		printf("here1");
		ft_print_type_c(val, ap);
	}
	/*
	else if (c == 's')
	else if (c == 'd')
	else if (c == 'p')
	else if (c == 'i')
	else if (c == 'u')
	else if (c == 'x')
	else if (*str == 'X')
	else
	*/
}
