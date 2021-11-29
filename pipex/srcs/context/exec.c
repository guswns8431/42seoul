/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:57:52 by hyson             #+#    #+#             */
/*   Updated: 2021/11/29 11:22:05 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	set_pipe_read(int *fd)
{
	dup2(fd[READ], READ);
	close(fd[WRITE]);
}

static	void	set_pipe_write(int *fd)
{
	dup2(fd[WRITE], WRITE);
	close(fd[READ]);
}

t_bool	exec(t_argvlist *arg, int *fd, char **envp, pid_t *pid)
{
	char	*cmd;

	if (*pid > 0)
	{
		cmd = ft_strjoin(arg->cmd2_path, "/");
		cmd = ft_strjoin(cmd, arg->cmd2);
		waitpid(*pid, NULL, WNOHANG);
		set_pipe_read(fd);
		redirection_stdout(arg->file2);
		if ((execve(cmd, arg->argv2, envp)) == ERROR)
			perror(arg->cmd2);
	}
	else if (*pid == 0)
	{
		cmd = ft_strjoin(arg->cmd1_path, "/");
		cmd = ft_strjoin(cmd, arg->cmd1);
		redirection_stdin(arg->file1);
		set_pipe_write(fd);
		if ((execve(cmd, arg->argv1, envp)) == ERROR)
			perror(arg->cmd1);
	}
	return (ERROR);
}
