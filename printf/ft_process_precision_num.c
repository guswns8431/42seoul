/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision_num.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:18:24 by hyson             #+#    #+#             */
/*   Updated: 2021/04/20 20:26:37 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_process_precision_num(int precision, int len)
{
	int i;
	int rt;

	rt = len;
	if (precision > len)
	{
		i = precision - len;
		rt = precision;
		while(i--)
			write(1, "0", 1);
	}
	return (rt);
}
