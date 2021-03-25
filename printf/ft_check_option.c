/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:07:40 by hyson             #+#    #+#             */
/*   Updated: 2021/03/25 19:13:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_option(t_option *val, char *c)
{
	if (*c == '-')
		val->minus = 1;
	else if (*c == '0')
		val->zero = 1;
	else if (*c >= '1' && *c <= '9' && val->dot == 0)
		val->width = ft_atoi(&c);
	else if (*c == '.')
		val->dot = 1;
	else if (*c >= '1' && *c <= '9' && val->dot == 1)
		val->precision = ft_atoi(&c);
	else
		return ;
}
