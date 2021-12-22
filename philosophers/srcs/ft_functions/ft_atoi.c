/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:42:10 by hyson             #+#    #+#             */
/*   Updated: 2021/12/22 16:37:31 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_atoi(const char *str, int *result)
{
	int			sign;

	sign = 1;
	*result = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!ft_isdigit(*str))
		return (FALSE);
	while (ft_isdigit(*str))
	{
		if ((*result >= 0) != ((*result << 1) >= 0) ||
			(*result >= 0) != ((*result << 2) >= 0) ||
			(*result >= 0) != ((*result << 3) >= 0) ||
			(*result >= 0) != (*result * 10 + (*str - '0') >= 0))
			return (FALSE);
		*result = *result * 10 + *str++ - '0';
	}
	if (*str && !ft_isspace(*str))
		return (FALSE);
	*result *= sign;
	return (TRUE);
}
