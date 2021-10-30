/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:09:56 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 17:17:42 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_output(int index, char **output, char **str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (index == 0 || index == 8)
		{
			if (str[1][index+(i*2)] == '1' && str[1][index+(i*2+8)] == '2')
			{
				output[0][i] = '4';
				output[1][i] = '1';
				output[2][i] = '2';
				output[3][i] = '3';
			}
			else if (str[1][index+(i*2)] == '2' && str[1][index+(i*2+8)] == '2')
			{
				output[0][i] = '3';
				output[1][i] = '4';
				output[2][i] = '1';
				output[3][i] = '2';
			}
			else if (str[1][index+(i*2)] == '3' && str[1][index+(i*2+8)] == '2')
			{
				output[0][i] = '2';
				output[1][i] = '3';
				output[2][i] = '4';
				output[3][i] = '1';
			}
			else if (str[1][index+(i*2)] == '4' && str[1][index+(i*2+8)] == '1')
			{
				output[0][i] = '1';
				output[1][i] = '2';
				output[2][i] = '3';
				output[3][i] = '4';
			}
		}
		else
		{
			if (str[1][index+(i*2)] == '1' && str[1][index+(i*2+8)] == '2')
			{
				output[i][0] = '4';
				output[i][1] = '1';
				output[i][2] = '2';
				output[i][3] = '3';
			}
			else if (str[1][index+(i*2)] == '2' && str[1][index+(i*2+8)] == '2')
			{
				output[i][0] = '3';
				output[i][1] = '4';
				output[i][2] = '1';
				output[i][3] = '2';
			}
			else if (str[1][index+(i*2)] == '3' && str[1][index+(i*2+8)] == '2')
			{
				output[i][0] = '2';
				output[i][1] = '3';
				output[i][2] = '4';
				output[i][3] = '1';
			}
			else if (str[1][index+(i*2)] == '4' && str[1][index+(i*2+8)] == '1')
			{
				output[i][0] = '1';
				output[i][1] = '2';
				output[i][2] = '3';
				output[i][3] = '4';
			}
		}
		i++;
	}
}
