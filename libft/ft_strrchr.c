/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:10:32 by hyson             #+#    #+#             */
/*   Updated: 2021/01/02 15:00:51 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t srclen;

	srclen = ft_strlen(s) + 1;
	while (srclen-- > 0)
		if (s[srclen] == (char)c)
			return ((char *)s + srclen);
	return (NULL);
}
