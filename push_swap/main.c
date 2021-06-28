/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:12:28 by hyson             #+#    #+#             */
/*   Updated: 2021/06/28 22:27:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isinteger(char *s)
{
	int i;
	long long num;

	i = -1;
	num = 0;
	while (s[++i])
		num = num * 10 + (s[i] - '0');
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

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
	while (++i < argc)
	{
		if (!ft_isnum(argv[i]) || !ft_isinteger(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
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
