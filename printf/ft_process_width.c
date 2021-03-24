/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:03:43 by hyson             #+#    #+#             */
/*   Updated: 2021/03/24 19:09:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_process_width(int len, int width)
{
	int i;
	printf("%d %d", len , width);
	if (len < width)
	{
		i = width - len;
		while (i--)
			write(1, " ", 1);
	}
	else
		return ;
}
