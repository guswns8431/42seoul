/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:59:35 by hyson             #+#    #+#             */
/*   Updated: 2021/03/25 19:09:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char **str)
{
	int	ret;

	ret = 0;
	while (ft_is_digit(**str))
	{
		ret = ret * 10 + **str - '0';
		++(*str);
	}
	return (ret);
}
