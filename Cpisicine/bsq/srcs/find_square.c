/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:35:24 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 06:45:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_square(t_map *nh_map)
{
	int i;
	int j;
	int tmp;
	int max[3];

	i = 1;
	max[0] = -1;
	while (i < nh_map->y)
	{
		j = 1;
		while (j < nh_map->x)
		{
			if (nh_map->result[i][j] != 0)
			{
				tmp = nh_min(nh_map->result[i - 1][j - 1],
						nh_map->result[i - 1][j], nh_map->result[i][j - 1]);
				nh_map->result[i][j] = tmp + 1;
				if (max[0] < (tmp + 1))
				{
					max[0] = tmp + 1;
					max[1] = i;
					max[2] = j;
				}
			}
			j++;
		}
		i++;
	}
	change_arr(max, nh_map);
	print_square(nh_map);
}

void	change_arr(int *max, t_map *nh_map)
{
	int i;
	int j;

	i = max[1] - (max[0] - 1);
	while (i <= max[1])
	{
		j = max[2] - (max[0] - 1);
		while (j <= max[2])
		{
			nh_map->arr[i][j] = 2;
			j++;
		}
		i++;
	}
}

void	print_square(t_map *nh_map)
{
	int i;
	int j;

	i = 0;
	while (i < nh_map->y)
	{
		j = 0;
		while (j < nh_map->x)
		{
			if (nh_map->arr[i][j] == 0)
				write(1, &nh_map->obstacle, 1);
			else if (nh_map->arr[i][j] == 1)
				write(1, &nh_map->blank, 1);
			else if (nh_map->arr[i][j] == 2)
				write(1, &nh_map->full, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
