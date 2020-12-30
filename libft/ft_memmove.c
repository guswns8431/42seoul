/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:20:00 by hyson             #+#    #+#             */
/*   Updated: 2020/12/30 16:11:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (!src && !dst)
		return (0);
	if (src >= dst)
	{
		i = -1;
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = len;
		while ((int)(--i) >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
