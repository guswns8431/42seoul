/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:54:59 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 07:35:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		fill_map_stdin(void)
{
	t_map *nh_map_stdin;

	if (!(nh_map_stdin = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (init_map_stdin(nh_map_stdin) == 0)
		return (0);
	fill_arr(nh_map_stdin, 0, 1);
	find_square(nh_map_stdin);
	nh_free(nh_map_stdin);
	free(nh_map_stdin);
	return (1);
}

int			init_map_stdin(t_map *nh_map_stdin)
{
	int		len;
	char	buf[1];
	char	info[30];
	char	*stdin_first;

	len = 0;
	read(0, buf, 1);
	while (1)
	{
		info[len] = buf[0];
		if (info[len] == '\n')
			break ;
		read(0, buf, 1);
		len++;
	}
	nh_map_stdin->info_len = len;
	if (len < 4)
		return (0);
	len -= 3;
	while (len--)
		if (!is_number(info[len]))
			return (0);
	get_y_stdin(nh_map_stdin, info);
	nh_map_stdin->blank = info[nh_map_stdin->info_len - 3];
	nh_map_stdin->obstacle = info[nh_map_stdin->info_len - 2];
	nh_map_stdin->full = info[nh_map_stdin->info_len - 1];
	if (!symbol_is_same(nh_map_stdin))
		return (0);
	stdin_first = get_x_stdin(nh_map_stdin);
	if (malloc_arr(nh_map_stdin) == 0)
		return (0);
	fill_stdin_first(stdin_first, nh_map_stdin);
	return (1);
}

void	fill_stdin_first(char *stdin_first, t_map *nh_map_stdin)
{
	int i;

	i = 0;
	while (i < nh_map_stdin->x)
	{
		if (stdin_first[i] == nh_map_stdin->blank)
		{
			nh_map_stdin->arr[0][i] = 1;
			nh_map_stdin->result[0][i] = 1;
		}
		else if (stdin_first[i] == nh_map_stdin->obstacle)
		{
			nh_map_stdin->arr[0][i] = 0;
			nh_map_stdin->result[0][i] = 0;
		}
		else
		{
			write(2, "map error", 9);
			write(1, "\n", 1);
			exit(0);
		}
		i++;
	}
}

int		get_y_stdin(t_map *nh_map_stdin, char *info)
{
	int i;
	int ans;

	i = 0;
	ans = 0;
	while (i < (nh_map_stdin->info_len - 3))
	{
		if (!is_number(info[i]))
			return (0);
		if (info[i] == '\n')
			break ;
		ans = (ans * 10) + (info[i] - '0');
		i++;
	}
	nh_map_stdin->y = ans;
	return (1);
}

char	*get_x_stdin(t_map *nh_map_stdin)
{
	int		k;
	int		len;
	char	*buf;
	char	*stdin_first;
	int		size;

	k = 0;
	size = 1024;
	buf = (char*)malloc(sizeof(char));
	stdin_first = (char*)malloc(sizeof(char) * size);
	len = 0;
	read(0, buf, 1);
	while (1)
	{
		stdin_first[k++] = buf[0];
		if (buf[0] == '\n')
			break ;
		read(0, buf, 1);
		++len;
		if (len == size)
			stdin_first = strdouble(stdin_first, size * 2);
	}
	nh_map_stdin->x = len;
	free(buf);
	return (stdin_first);
}

char	*strdouble(char *str, int size)
{
	char *temp;

	temp = (char*)malloc(sizeof(char) * size);
	ft_strcpy(temp, str);
	free(str);
	return (temp);
}

void		ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		++src;
		++dest;
	}
}
