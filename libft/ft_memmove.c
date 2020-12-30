/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:20:00 by hyson             #+#    #+#             */
/*   Updated: 2020/12/30 14:59:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*psrc;
	char		*pdst;
	size_t		i;

	psrc = src;
	pdst = dst;
	if (!psrc && !pdst)
		return (0);
	if (psrc >= pdst)
	{
		i = -1;
		while (++i < len)
			pdst[i] = psrc[i];
	}
	else
	{
		i = len;
		while ((int)(--i) >= 0)
			pdst[i] = psrc[i];
	}
	return (pdst);
}
