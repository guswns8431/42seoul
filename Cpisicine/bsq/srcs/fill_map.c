/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:22:43 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 06:34:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_map(char *argv)
{
	int		fd;
	t_map	*nh_map;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (0);
	if (!(nh_map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (init_map(nh_map, fd, argv) == 0)
		return (0);
	if (malloc_arr(nh_map) == 0)
		return (0);
	fill_arr(nh_map, fd, 0);
	if (!symbol_is_same(nh_map))
		return (0);
	find_square(nh_map);
	close(fd);
	nh_free(nh_map);
	free(nh_map);
	return (1);
}

int		init_map(t_map *nh_map, int fd, char *argv)
{
	int		fd2;
	int		len;
	char	*buf;

	if ((fd2 = (open(argv, O_RDONLY))) < 0)
		return (0);
	if (!get_y(nh_map, fd, fd2, &len))
		return (0);
	buf = (char *)malloc(sizeof(char) * len);
	read(fd2, buf, 1);
	nh_map->blank = buf[0];
	read(fd2, buf, 1);
	nh_map->obstacle = buf[0];
	read(fd2, buf, 1);
	nh_map->full = buf[0];
	get_x(nh_map, fd2);
	close(fd2);
	free(buf);
	return (1);
}

int		get_y(t_map *nh_map, int fd, int fd2, int *len)
{
	char	*buf;
	int		i;

	buf = (char*)malloc(sizeof(char));
	*len = 0;
	while (1)
	{
		read(fd, buf, 1);
		if (buf[0] == '\n')
			break ;
		++(*len);
	}
	nh_map->info_len = *len;
	if ((*len) < 4)
		return (0);
	free(buf);
	buf = (char*)malloc(sizeof(char) * (*len));
	read(fd2, buf, (*len) - 3);
	i = 0;
	while (i < (*len) - 3)
		if (!(is_number(buf[i++])))
			return (0);
	nh_map->y = nh_atoi(buf, (*len) - 3);
	free(buf);
	return (1);
}

void	get_x(t_map *nh_map, int fd2)
{
	int		len;
	char	*buf;

	buf = (char*)malloc(sizeof(char));
	len = 0;
	read(fd2, buf, 1);
	while (1)
	{
		read(fd2, buf, 1);
		if (buf[0] == '\n')
			break ;
		++len;
	}
	nh_map->x = len;
	free(buf);
}
