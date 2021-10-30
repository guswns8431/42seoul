/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:50:47 by hyson             #+#    #+#             */
/*   Updated: 2020/12/06 20:13:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *dptr;
	char *pstr;
	char *tmp;

	pstr = src;
	while (*pstr)
		pstr++;
	dptr = malloc(pstr - src + 1);
	if (!dptr)
		return (NULL);
	tmp = dptr;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dptr);
}
