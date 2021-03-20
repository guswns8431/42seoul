/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:37:18 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 19:43:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_type(char c, t_option *val)
{
	if (c == 'c')
		ft_print_type_c(val, c);
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
