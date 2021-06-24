/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:12:28 by hyson             #+#    #+#             */
/*   Updated: 2021/06/24 21:52:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_error(int argc, char **argv)
{
	int i;
	int j;

	i = 0;

	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			write(1, &argv[i][j], 1);
	}
}

int main(int argc, char **argv)
{
	check_error(argc, argv);
	return (0);
}
