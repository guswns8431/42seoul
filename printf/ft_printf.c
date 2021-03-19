/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:55:51 by hyson             #+#    #+#             */
/*   Updated: 2021/03/19 23:36:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		tmp;
	int		i;

	i = 0;
	va_start(ap, args);
	write(1, args, 1);
	tmp = va_arg(ap, int);
	while (++i <= 2)
	{
		write(1, &tmp, 1);
		tmp = va_arg(ap, int);
	}
	va_end(ap);
	return (ft_strlen(args));
}

int	main(void)
{
	char	str1;
	char	str2;

	str1 = 'c';
	str2 = 'd';
	ft_printf("a", 'b', 'c');
	return (0);
}
