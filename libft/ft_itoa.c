/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 01:13:23 by hyson             #+#    #+#             */
/*   Updated: 2021/01/10 02:29:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static size_t	ft_intlen(int n)
{
	int	len;

	len = n > 0 ? 0 : 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	int		i;

	i = 0;
	len = ft_intlen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		i = 1;
	}
	s[len] = '\0';
	while ((int)--len >= i)
	{
		s[len] = ft_abs(n) % 10 + '0';
		n /= 10;
	}
	return (s);
}
