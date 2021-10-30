/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:31:48 by hyson             #+#    #+#             */
/*   Updated: 2020/12/01 11:03:29 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *tmp;

	tmp = dest;
	while (*dest)
	{
		dest++;
	}
	while (nb > 0 && *src)
	{
		*dest = *(unsigned char *)src;
		src++;
		dest++;
		nb--;
	}
	*dest = '\0';
	return (tmp);
}
