/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/13 22:16:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	printf("%d", argc);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		e_file_open();
	get_next_line(fd, &line);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
