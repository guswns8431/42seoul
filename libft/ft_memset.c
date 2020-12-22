/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:41:04 by hyson             #+#    #+#             */
/*   Updated: 2020/12/22 14:33:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char*)dest)[i] = value;
		i++;
	}
	return (dest);
}
