/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:55:57 by hyson             #+#    #+#             */
/*   Updated: 2020/12/22 15:57:54 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dest)[i] = 0;
		i++;
	}
}
