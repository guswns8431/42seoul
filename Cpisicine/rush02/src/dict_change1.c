/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_change1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:41:26 by hyson             #+#    #+#             */
/*   Updated: 2020/12/06 14:53:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	dict_change1(char *str)
{
	int		fd;
	char	buf[100];
	int		i;
	int		n;

	i = 0;
	fd = open("dictionary/numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "fail to open dict file\n", 23);
		return ;
	}
	n = read(fd, buf, 50);
	while (i < n)
	{
		if (buf[i] == *str)
		{
			write(1, &buf[i + 3], 5);
			break ;
		}
		i++;
	}
	close(fd);
}
