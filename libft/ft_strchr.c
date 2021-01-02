/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:07:49 by hyson             #+#    #+#             */
/*   Updated: 2020/12/31 18:46:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t srclen;

	srclen = ft_strlen(s) + 1;
	while (srclen-- > 0)
		if (*s++ == (char)c)
			return ((char *)--s);
	return (NULL);
}
