/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:03:43 by hyson             #+#    #+#             */
/*   Updated: 2021/04/21 17:12:42 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_process_width_num(int len, int width, int zero, int dot)
{
	int i;
	int rt;

	if (width != 0 && len < width)
	{
		i = width - len;
		rt = i;
		if (zero && !dot)
			while (i--)
				write(1, "0", 1);
		else
			while (i--)
				write(1, " ", 1);
		return (rt);
	}
	else
		return (0);
}
