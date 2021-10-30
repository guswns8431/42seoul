/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:48:12 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 06:54:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		malloc_arr(t_map *nh_map)
{
	int i;

	if (!(nh_map->arr = (int**)malloc(sizeof(int*) * nh_map->y)))
		return (0);
	if (!(nh_map->result = (int**)malloc(sizeof(int*) * nh_map->y)))
		return (0);
	i = -1;
	while (++i < nh_map->y)
	{
		if (!(nh_map->arr[i] = (int*)malloc(sizeof(int) * nh_map->x)))
			return (0);
		if (!(nh_map->result[i] = (int*)malloc(sizeof(int) * nh_map->x)))
			return (0);
	}
	return (1);
}

void	fill_arr(t_map *nh_map, int fd, int i)
{
	char	buf[1];
	int		j;

	while (i < nh_map->y)
	{
		j = 0;
		while (j < nh_map->x)
		{
			read(fd, buf, 1);
			if (buf[0] != '\n')
			{
				if (buf[0] == nh_map->blank)
				{
					nh_map->arr[i][j] = 1;
					nh_map->result[i][j] = 1;
				}
				else if (buf[0] == nh_map->obstacle)
				{
					nh_map->arr[i][j] = 0;
					nh_map->result[i][j] = 0;
				}
				else
				{
					write(2, "map error", 9);
					write(1, "\n", 1);
					exit(0);
				}
				j++;
			}
		}
		i++;
	}
	read(fd, buf, 1);
	if (read(fd, buf, 1) != 0)
	{
		write(2, "map error", 9);
		write(1, "\n", 1);
		exit(0);
	}
}

void	nh_free(t_map *nh_map)
{
	int i;

	i = 0;
	while (i < nh_map->y)
	{
		free(nh_map->arr[i]);
		free(nh_map->result[i]);
		i++;
	}
	free(nh_map->arr);
	free(nh_map->result);
}
