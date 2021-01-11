/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:25:30 by hyson             #+#    #+#             */
/*   Updated: 2021/01/11 17:48:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		if ((result >= 0) != ((result << 1) >= 0) ||
			(result >= 0) != ((result << 2) >= 0) ||
			(result >= 0) != ((result << 3) >= 0) ||
			(result >= 0) != (result * 10 + (*str - '0') >= 0))
			return (sign == 1 ? -1 : 0);
		result = result * 10 + *str++ - '0';
	}
	return (sign * result);
}
