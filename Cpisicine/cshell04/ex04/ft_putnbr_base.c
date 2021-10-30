/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:37:49 by hyson             #+#    #+#             */
/*   Updated: 2020/12/02 20:55:11 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str)
	{
		strlen++;
		str++;
	}
	return (strlen);
}

int		ft_check_validation(char *base)
{
	char	*base_addr;
	int		i;
	int		j;
	int		flag;

	base_addr = base;
	if (!*base || ft_strlen(base) == 1)
		return (0);
	while (*base_addr)
	{
		if (*base_addr++ == '-' || *base_addr++ == '+')
			return (0);
	}
	i = -1;
	flag = 0;
	while (++i < ft_strlen(base))
	{
		j = i;
		while (++j <= ft_strlen(base))
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base_recursive(int nbr, char *base, int radix)
{
	if (nbr == -2147483648)
	{
		ft_putnbr_base_recursive(nbr / radix, base, radix);
		write(1, &base[-(nbr % radix)], 1);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursive(-nbr, base, radix);
	}
	else
	{
		if (nbr > radix - 1)
		{
			ft_putnbr_base_recursive(nbr / radix, base, radix);
		}
		write(1, &base[nbr % radix], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!(ft_check_validation(base)))
		return ;
	ft_putnbr_base_recursive(nbr, base, ft_strlen(base));
}
