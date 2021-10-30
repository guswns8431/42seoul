/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:28:50 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 07:29:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		nh_atoi(char *buf, int len)
{
	int i;
	int digit;

	i = 0;
	digit = 0;
	while (i < len)
		digit = digit * 10 + (buf[i++] - '0');
	return (digit);
}

int		nh_min(int a, int b, int c)
{
	int		min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}
