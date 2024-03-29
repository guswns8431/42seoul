/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index_24.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:55:07 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 16:55:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_index_24(char *preset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[1][i * 2] == preset[j])
			{
				preset[j] = '0';
				break ;
			}
			j++;
		}
		i++;
		if (preset[0] == '0' && preset[1] == '0')
		{
			if (preset[2] == '0' && preset[3] == '0')
				return (24);
		}
		return (1);
	}
}
