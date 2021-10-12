/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:17:39 by hyson             #+#    #+#             */
/*   Updated: 2021/10/12 18:44:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;

	argc = 0;
	argv = NULL;

	fd = open("./rt/example.rt", O_RDONLY);
	get_next_line(fd, &line);

	printf("test: %s\n", line);
	get_next_line(fd, &line);

	printf("test: %s\n", line);
	free(line);
	close(fd);
	return (0);
}
