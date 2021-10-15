/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/14 20:28:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		ret;

	if (argc != 2)
		e_file_param();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		e_file_open();
	while (TRUE)
	{
		ret = get_next_line(fd, &line);
		if (ret == END)
			break ;
		if (ret < 0)
				e_file_read(fd);
		if (parse(line, fd))
			continue ;
		free_ptr((void **)(&line));
	}
	close(fd);
	return (0);
}
