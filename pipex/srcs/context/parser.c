/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:04:13 by hyson             #+#    #+#             */
/*   Updated: 2021/11/16 21:21:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	t_bool	parse_envp(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if ((ft_strnstr(envp[i], "PATH=", 6) == envp[i]))
			break ;
		i++;
	}

	//동적할당(몇개를 할지 어떻게 정할래)

	//경로 하나씩 나눠서 담기
}

void	parser(char **argv, t_argvlist *args, char **envp)
{

	args->file1 = ft_strdup(argv[1]);
	args->cmd1 = ft_strdup(argv[2]);
	args->cmd2 = ft_strdup(argv[3]);
	args->file2 = ft_strdup(argv[4]);
	parse_envp(envp);
}
