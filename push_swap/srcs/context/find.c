/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:54:09 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 21:38:53 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_asc(int v1, int v2)
{
	return (v1 < v2);
}

bool	is_dsc(int v1, int v2)
{
	return (v1 > v2);
}

void	find_array(t_node *tmp, int *arr, int size)
{
	int		i;
	int		j;
	int		v;

	i = -1;
	while (++i < size && tmp)
	{
		arr[i] = tmp->v;
		tmp = tmp->n;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				v = arr[i];
				arr[i] = arr[j];
				arr[j] = v;
			}
		}
	}
}

bool	find_pivot(t_node *tmp, int *p1, int *p2, int size)
{
	int		*arr;

	if (!ft_calloc((void **)(&arr), size, sizeof(int)))
		return (false);
	find_array(tmp, arr, size);
	if (!(size % 3))
	{
		*p1 = arr[size / 3 + 1];
		*p2 = arr[2 * (size + 1) / 3 - 1];
	}
	else
	{
		*p1 = arr[size / 3 + 1];
		*p2 = arr[(size * 2) / 3];
	}
	ft_free((void **)(&arr));
	return (true);
}

bool	find_deter(t_node *tmp, int size, bool (*f)(int, int))
{
	int		i;

	i = -1;
	while (++i < size - 1)
	{
		if (f(tmp->v, tmp->n->v))
			return (false);
		tmp = tmp->n;
	}
	return (true);
}
