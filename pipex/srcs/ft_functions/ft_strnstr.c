/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:35:26 by hyson             #+#    #+#             */
/*   Updated: 2021/11/29 11:09:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	while (needle_len <= len && len-- > 0)
		if (ft_memcmp(haystack++, needle, needle_len) == 0)
			return ((char *)--haystack);
	return (NULL);
}
