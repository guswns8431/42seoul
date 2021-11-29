/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:41:20 by hyson             #+#    #+#             */
/*   Updated: 2021/11/29 11:09:38 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char *)malloc(len + 1);
	if (!sub || !s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || !ft_strlcpy(sub, s + start, len + 1))
		sub[0] = '\0';
	return (sub);
}
