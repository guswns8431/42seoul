/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 01:15:32 by hyson             #+#    #+#             */
/*   Updated: 2020/11/30 17:37:43 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find(char *str, char *to_find)
{
	char	*str_add;
	char	*to_find_add;

	str_add = str;
	to_find_add = to_find;
	while (*to_find_add)
	{
		if (*to_find_add != *str_add)
			return (0);
		to_find_add++;
		str_add++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			if (ft_find(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
