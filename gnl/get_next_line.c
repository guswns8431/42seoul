/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:42:33 by hyson             #+#    #+#             */
/*   Updated: 2021/05/10 17:26:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_backup(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	


int	get_next_line(int fd, char **line)
{
	static char *save[OPEN_MAX];
	char 	*buf;
	int	read_size;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !buf)
		return (ERROR);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		save[fd] = ft_backup(save[fd], buf);
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
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
