/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:09:58 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 07:43:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	int		x;
	int		y;
	int		info_len;
	char	blank;
	char	obstacle;
	char	full;
	int		**arr;
	int		**result;
}				t_map;

int		fill_map(char *argv);
int		nh_atoi(char *buf, int len);
int		init_map(t_map *nh_map, int fd, char *argv);
int		get_y(t_map *nh_map, int fd, int fd2, int *len);
void	get_x(t_map *nh_map, int fd2);
int		malloc_arr(t_map *nh_map);
void	fill_arr(t_map *nh_map, int fd, int i);
int		symbol_is_same(t_map *nh_map);
int		symbol_is_non_printable(t_map *nh_map);
int		is_number(char nb);
int		nh_min(int a, int b, int c);
void	find_square(t_map *nh_map);
void	change_arr(int *max, t_map *nh_map);
void	print_square(t_map *nh_map);
void	nh_free(t_map *nh_map);
int		fill_map_stdin();
int		init_map_stdin(t_map *nh_map_stdin);
int		get_y_stdin(t_map *nh_map_stdin, char *info);
char	*get_x_stdin(t_map *nh_map_stdin);
char	*strdouble(char *str, int size);
void	ft_strcpy(char *dest, char *src);
void	fill_stdin_first(char *stdin_first, t_map *nh_map_stdin);
void	print_err(void);
#endif
