/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:03:43 by hyson             #+#    #+#             */
/*   Updated: 2021/03/29 16:37:32 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_process_width(int len, int width, int zero, int dot)
{
	int i;
	if (width != 0 && len < width)
	{
		i = width - len;
		if (zero && !dot)
			while (i--)
				write(1, "0", 1);
		else
			while (i--)
				write(1, " ", 1);
	}
	else
		return ;
}
