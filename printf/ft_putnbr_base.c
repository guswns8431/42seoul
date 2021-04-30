/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:58:36 by hyson             #+#    #+#             */
/*   Updated: 2021/04/30 15:17:29 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr_base(long long nb, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nb, base);
	}
	else
	{
		if (nb > base_len - 1)
			ft_putnbr_base(nb / base_len, base);
		ft_putchar(base[nb % base_len]);
	}
}
