/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:56:15 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 16:56:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	overflowed(int former, int latter)
{
	if (((former >= 0) != ((former << 1) >= 0))
		|| ((former >= 0) != ((former << 2) >= 0))
		|| ((former >= 0) != ((former << 3) >= 0))
		|| ((former >= 0) != (latter >= 0)))
		return (true);
	return (false);
}

bool	ft_atoi(char **s, int *v)
{
	int	sign;
	int	tmp;

	while (ft_isspace(**s))
		++(*s);
	sign = 1;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	if (!ft_isdigit(**s))
		return (false);
	*v = (*((*s)++) - '0') * sign;
	while (ft_isdigit(**s))
	{
		tmp = (*((*s)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *v * 10 + tmp;
		if (overflowed(*v, tmp))
			return (false);
		*v = tmp;
	}
	return (true);
}
