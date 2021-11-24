/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:04:13 by hyson             #+#    #+#             */
/*   Updated: 2021/11/24 20:22:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	parse_valid_path(char **arg_path, t_argvlist *args)
{
	int i;
	char *cmd;

	i = 0;
	while (arg_path[i])
	{
		cmd = ft_strjoin(arg_path[i], "/");
		cmd = ft_strjoin(cmd, args->cmd1);
		if (access(cmd, X_OK) != -1)
			args->cmd1_path = ft_strdup(arg_path[i]);
		ft_free((void **)&cmd);
		++i;
	}
	i = 0;
	while (arg_path[i])
	{
		cmd = ft_strjoin(arg_path[i], "/");
		cmd = ft_strjoin(cmd, args->cmd2);
		if (access(cmd, X_OK) != -1)
			args->cmd2_path = ft_strdup(arg_path[i]);
		ft_free((void **)&cmd);
		++i;
	}
}

static	t_bool	parse_envp(char **envp, t_argvlist *args)
{
	int i;
	char **tmp;

	i = 0;
	while (envp[i])
	{
		if ((ft_strnstr(envp[i], "PATH=", 5) == envp[i]))
			break ;
		i++;
	}
	tmp = ft_split(&(envp[i][5]), ':');
	parse_valid_path(tmp, args);
	return (SUCCESS);
}

void	parser(char **argv, t_argvlist *args, char **envp)
{

	args->file1 = *ft_split(argv[1], ' ');
	args->cmd1 = *ft_split(argv[2], ' ');
	args->cmd2 = *ft_split(argv[3], ' ');
	args->file2 = *ft_split(argv[4], ' ');
	args->argv1 = ft_split(argv[2], ' ');
	args->argv2 = ft_split(argv[3], ' ');
	parse_envp(envp, args);
}
