/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:11:32 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 16:27:46 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_len(char **str)
{
	int check_len;
	int i;

	check_len = 0;
	i = 0;
	while (str[1][i] != '\0')
	{
		check_len++;
		i++;
	}
	if (check_len != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
