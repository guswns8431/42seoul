/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:12:28 by hyson             #+#    #+#             */
/*   Updated: 2021/06/25 21:00:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnum(char *s)
{
	int i;

	i = -1;
	while(s[++i])
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

void	ft_check_error(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			if (!ft_isnum(argv[j]) || ft_strcmp(argv[i], argv[j]))
			{
					write(2, "Error\n", 6);
					exit(0);
			}
		}
	}
}


int		main(int argc, char **argv)
{
	ft_check_error(argc, argv);
	return (0);
}
