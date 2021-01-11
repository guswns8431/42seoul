/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 00:31:26 by hyson             #+#    #+#             */
/*   Updated: 2021/01/11 15:43:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				++s;
			++len;
		}
		else
			++s;
	}
	return (len);
}

char	**ft_free_dptr(char **s, int i)
{
	while (--i >= 0 && s[i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}
char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	char	*tmp;

	i = 0;
	if (!s || !(ret = (char **)malloc((ft_wordlen(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while (*s && *s != c)
				++s;
			if (!(ret[i++] = ft_substr(tmp, 0, s - tmp)))
				return (ft_free_dptr(ret, i));
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
