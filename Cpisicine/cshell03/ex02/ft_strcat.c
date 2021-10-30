/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:08:48 by hyson             #+#    #+#             */
/*   Updated: 2020/11/26 21:06:51 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *tmp;

	tmp = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *(unsigned char *)src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (tmp);
}
