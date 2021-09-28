/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:04:13 by hyson             #+#    #+#             */
/*   Updated: 2021/09/28 17:39:51 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parser(char **argv, t_argvlist *args)
{
	args->file1 = ft_strdup(argv[1]);
	args->cmd1 = ft_strdup(argv[2]);
	args->cmd2 = ft_strdup(argv[3]);
	args->file2 = ft_strdup(argv[4]);
}
