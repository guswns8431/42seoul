/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:46:13 by hyson             #+#    #+#             */
/*   Updated: 2020/12/31 17:43:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (i < dstsize - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dstlen + srclen);
}
