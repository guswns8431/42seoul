/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:40:03 by hyson             #+#    #+#             */
/*   Updated: 2021/11/23 14:48:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	redirection_stdin(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		return (FAIL);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

bool	redirection_stdout(char *path)
{
	int fd;

	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(path);
		return (FAIL);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}
