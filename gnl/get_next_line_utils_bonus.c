/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:28:34 by hyson             #+#    #+#             */
/*   Updated: 2021/05/14 16:13:43 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dstsize)
	{
		while (src[i] && (i < dstsize - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, len + 1);
	return (dup);
}

t_bool	dalloc(void **ptr, size_t cnt, size_t n)
{
	size_t	i;

	i = -1;
	*ptr = (void *)malloc(cnt * n);
	if (!*ptr)
		return (FALSE);
	while (++i < n)
		(*(unsigned char **)ptr)[i] = '\0';
	return (TRUE);
}

void	free_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}
