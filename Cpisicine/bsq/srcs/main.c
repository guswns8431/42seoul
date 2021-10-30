/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:17:20 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 07:42:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char *argv[])
{
	int err;
	int i;

	err = 1;
	if (argc == 1)
	{
		err = fill_map_stdin();
		if (err == 0)
			print_err();
	}
	else if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{
			err = fill_map(argv[i]);
			if (err == 0)
				print_err();
			i++;
		}
	}
	return (0);
}

void	print_err(void)
{
	write(2, "map error", 9);
	write(1, "\n", 1);
}
