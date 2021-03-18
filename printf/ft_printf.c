/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:55:51 by hyson             #+#    #+#             */
/*   Updated: 2021/03/19 00:23:01 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(int args, ...)
{
	va_list	ap;
	int	tmp;

	va_start(ap, args);
	tmp = va_arg(ap, int);
	while (tmp++)
		write(1, &tmp, 1);
	va_end(ap);
	return (0);
}

int 	main(void)
{
	ft_printf(1, 1);
	return (0);
}
