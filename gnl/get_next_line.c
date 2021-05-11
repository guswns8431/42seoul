/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:42:33 by hyson             #+#    #+#             */
/*   Updated: 2021/05/11 19:05:42 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/fcntl.h>

static t_bool	ft_backup(char **s, char *s1, char *s2)
{
	if (!s1 && !s2)
		return (FALSE);
	if (!s1)
	{
		*s = ft_strdup(s2);
		free_ptr((void **)(&s1));
		if (!*s)
			return (FALSE);
		return (TRUE);
	}
	else if (!s2)
    {
        *s = s1;
		return (TRUE);
    }
	if (!dalloc((void **)(s), ft_strlen(s1) + ft_strlen(s2) + 1, 1))
	{
		free_ptr((void **)(&s1));
		return (FALSE);
	}
	ft_strlcpy(*s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(*s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
    free_ptr((void **)(&s1));
	return (TRUE);
}

static t_bool	ft_check_newline(char *str, int *ret)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			*ret = i;
			return (TRUE);
		}
	}
	*ret = -1;
	return (FALSE);
}

static int		ft_split_line(char **save, char **line, int idx)
{
	char	*tmp;

	(*save)[idx] = '\0';
	*line = ft_strdup(*save);
    if (!*line)
    {
            free_ptr((void **)(save));
            return (ERROR);
    }
	if (!ft_strlen(*save + idx + 1))
	{
        free_ptr((void **)(save));
		return (SUCCESS);
	}
    tmp = *save;
	*save = ft_strdup(*save + idx + 1);
    free_ptr((void **)(&tmp));
    if (!*save)
            return (ERROR);
	return (SUCCESS);
}

static int		ft_exception(char **save, char **line, int read_size)
{
	int	idx;

    idx = -1;
	if (read_size < 0)
	{
		free_ptr((void **)(save));
		return (ERROR);
	}
	if (*save)
	{
		if (ft_check_newline(*save, &idx))
			return (ft_split_line(save, line, idx));
		*line = *save;
		*save = NULL;
		return (END);
	}
	if (!dalloc((void **)(&line), 1, sizeof(char)))
	{
		free_ptr((void **)(save));
		return (ERROR);
	}
	return (END);
}

int				get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || OPEN_MAX <= fd ||
		!dalloc((void **)(&buf), BUFFER_SIZE + 1, 1))
		return (ERROR);
	while (TRUE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = '\0';
		if (ret <= 0)
			break ;
		if (!ft_backup((&(save[fd])), save[fd], buf))
		{
			free_ptr((void **)(&buf));
			return (ERROR);
		}
		if (ft_check_newline(save[fd], &ret))
		{
			free_ptr((void **)(&buf));
			return (ft_split_line(&save[fd], line, ret));
		}
	}
	free_ptr((void **)(&buf));
	return (ft_exception(&save[fd], line, ret));
}

  int main(void)
  {
          int fd = open("hi", O_RDONLY);
          char *line;
 
          line = NULL;
          int ret = get_next_line(fd, &line);
          printf("%d, %s\n", ret, line);
          return (0);
  }
  
