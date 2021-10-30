/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 18:33:50 by hyson             #+#    #+#             */
/*   Updated: 2020/12/08 18:34:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tmp;
	int ret;

	ret = max - min;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * ret);
	if (!*range)
		return (-1);
	tmp = *range;
	while (min < max)
		*tmp++ = min++;
	return (ret);
}
