/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:12:28 by hyson             #+#    #+#             */
/*   Updated: 2021/06/25 19:35:26 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

void	check_error(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc - 1)
	{
		j = i + 1;
		while (++j < argc)
			if (ft_strcmp(argv[i], argv[j]))
			{
					write(2, "Error\n", 6);
					exit(0);
			}
	}
}


int		main(int argc, char **argv)
{
	check_error(argc, argv);
	return (0);
}
