/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_precision_num.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:18:24 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 15:18:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_process_precision_num(int precision, int len)
{
	int	i;

	if (precision > len)
	{
		i = precision - len;
		while (i--)
			write(1, "0", 1);
	}
}
