/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:01:14 by hyson             #+#    #+#             */
/*   Updated: 2021/07/01 20:05:09 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_calloc(void **tmp, size_t cnt, size_t size)
{
	*tmp = (void *)malloc(cnt * size);
	if (!*tmp)
		return (false);
	ft_memset(*tmp, 0, cnt * size);
	return (true);
}
