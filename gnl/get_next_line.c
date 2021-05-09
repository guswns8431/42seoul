/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:42:33 by hyson             #+#    #+#             */
/*   Updated: 2021/05/09 22:31:53 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *tmp;
	
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);

	printf("tmp : %s\n", tmp);
	tmp = *line;
	if(read(fd, *line, 10) == -1)
		printf("read error\n");

	printf("%s\n", *line);
	return (0);
}

int main()
{
	int fd;
	char *s;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cannot open file\n");
		return (1);
	}
	get_next_line(fd, &s);
	get_next_line(fd, &s);
	return (0);
}
