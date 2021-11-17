/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:07:55 by hyson             #+#    #+#             */
/*   Updated: 2021/11/17 18:14:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_argvlist args;

	ft_memset(&args, 0, sizeof(t_argvlist));
	if (argc != 5)
		exit_invalid();
	parser(argv, &args, envp);
	return (0);
}
