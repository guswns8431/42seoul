/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:42:33 by hyson             #+#    #+#             */
/*   Updated: 2021/05/11 00:17:48 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_backup(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	else
		return (s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, s2_len + 1);
	return (ret);
}

int	ft_check_newline(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
			if (str[i] == '\n')
				return (i);
	return (-1);
}

int		ft_split_line(char **save, char **line, int idx)
{
	char	*tmp;

	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
	if (!ft_strlen(*save + idx + 1))
	{
		free(*save);
		*save = NULL;
		return (HAS_BEEN_READ);
	}
	tmp = ft_strdup(*save + idx + 1);
	free(*save);
	*save = tmp;
	return (HAS_BEEN_READ);
}

int		ft_exception(char **save, char **line, int read_size)
{
	int idx;

	if (read_size < 0)
		return (ERROR);
	idx = ft_check_newline(*save);
	if (*save && idx >= 0)
		return (ft_split_line(save, line, idx));
	else if (*save)
	{
		*line = *save;
		*save = NULL;
		return (EOF_REACHED);
	}
	*line = ft_strdup("");
	return (EOF_REACHED);
}

int	get_next_line(int fd, char **line)
{
	static char *save[OPEN_MAX];
	char 	*buf;
	int	read_size;
	int	index;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ERROR);
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		save[fd] = ft_backup(save[fd], buf);
		index = ft_check_newline(save[fd]);
		if (index >= 0)
		{
			free(buf);
			buf = NULL;
			return (ft_split_line(&save[fd], line, index));
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	return (ft_exception(&save[fd], line, read_size));
}
