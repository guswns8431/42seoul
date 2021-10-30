/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:24:44 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 17:17:31 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // for debug


int		check_len(char **str);
int		check_input(int index, char **str);
void	set_output(int index, char **output);
int		check_4321(char **str);

void	rush01(char **str)
{
	int i;
	int j;
	int index;
	char output[4][4];

	if (check_len(char **str))
		return ;
	if (check_4321(str) == 1)
		return ;
	index = check_4321(str);
	if (check_input(index, str) != 1)
		return ;
	set_output(index, output);
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &output[i][j], 1);
			if (j != 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
