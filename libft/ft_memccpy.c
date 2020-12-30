/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:42:01 by hyson             #+#    #+#             */
/*   Updated: 2020/12/25 16:12:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*psrc;
	unsigned char		*pdst;

	psrc = src;
	pdst = dst;
	if (!src && !dst)
		return (0);
	while (n-- > 0)
	{
		*pdst++ = *psrc++;
		if (*psrc == (unsigned char)c)
		{
			*pdst++ = *psrc;
			return (pdst);
		}
	}
	return (NULL);
}
