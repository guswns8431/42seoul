/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:37:18 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 19:49:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_is_type(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'd')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else
		return (1);
	return (0);
}

