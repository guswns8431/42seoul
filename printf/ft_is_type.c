/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:37:18 by hyson             #+#    #+#             */
/*   Updated: 2021/04/18 00:46:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_is_type(char *c)
{
	if (*c == 'c')
		return (1);
	else if (*c == 's')
		return (1);
	else if (*c == 'd')
		return (1);
	else if (*c == 'p')
		return (1);
	else if (*c == 'i')
		return (1);
	else if (*c == 'u')
		return (1);
	else if (*c == 'x')
		return (1);
	else if (*c == 'X')
		return (1);
	else if (*c == '%') //이 부분 %를 위해서 추가했어요
		return (1);
	else
		return (0);
	return (0);
}

