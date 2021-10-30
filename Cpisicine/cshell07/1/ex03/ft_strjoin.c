/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:39:17 by hyson             #+#    #+#             */
/*   Updated: 2020/12/08 20:41:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int strlen;

	strlen = 0;
	while (*str)
	{
		str++;
		strlen++;
	}
	return (strlen);
}

char	*ft_strcpy(char *dest, char *src)
{
	while ((*dest++ = *src++))
		;
	return (--dest);
}

void	ft_fill_str(char *tmp, char **strs, int size, char *sep)
{
	int i;

	i = 0;
	tmp = ft_strcpy(tmp, strs[i]);
	while (++i < size)
	{
		tmp = ft_strcpy(tmp, sep);
		tmp = ft_strcpy(tmp, strs[i]);
	}
	*tmp = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		str_length;

	str_length = 0;
	if (!size)
	{
		join = (char *)malloc(1);
		if (!join)
			return (0);
		join[0] = 0;
		return (join);
	}
	i = 0;
	while (i < size)
		str_length += ft_strlen(strs[i++]);
	join = (char *)malloc(sizeof(char) * str_length
			* (ft_strlen(sep) * (size - 1)) + 1);
	if (!join)
		return (0);
	ft_fill_str(join, strs, size, sep);
	return (join);
}
