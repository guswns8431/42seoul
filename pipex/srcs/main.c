/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:07:55 by hyson             #+#    #+#             */
/*   Updated: 2021/11/29 11:01:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_argvlist	args;
	int			fd[2];
	pid_t		pid;

	ft_memset(&args, 0, sizeof(t_argvlist));
	if (argc != 5)
		exit_invalid();
	parser(argv, &args, envp);
	if (!args.cmd1_path || !args.cmd2_path)
	{
		perror("cmd path");
		exit_invalid();
	}
	if (pipe(fd) == ERROR)
	{
		perror("pipe");
		exit_invalid();
	}
	pid = fork();
	if ((exec(&args, fd, envp, &pid)) == ERROR)
		exit_invalid();
	return (0);
}
