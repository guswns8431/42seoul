/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_index_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:47:21 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 16:53:20 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_index_0(char *preset)
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
				return (0);
		}
		return (1);
	}
}
