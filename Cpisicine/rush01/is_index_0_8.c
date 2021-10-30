/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_index_0_8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:47:12 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 19:47:14 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_index_0_8(char **str, int index, int i)
{
	if (str[1][index + (i * 2)] == '1' && str[1][index + (i * 2 + 8)] == '2')
	{
		output[0][i] = '4';
		output[1][i] = '1';
		output[2][i] = '2';
		output[3][i] = '3';
	}
	else if (str[1][index + (i * 2)] == '2' && str[1][index + (i * 2 + 8)] == '2')
	{
		output[0][i] = '3';
		output[1][i] = '4';
		output[2][i] = '1';
		output[3][i] = '2';
	}
	else if (str[1][index+(i * 2)] == '3' && str[1][index + (i * 2 + 8)] == '2')
	{
		output[0][i] = '2';
		output[1][i] = '3';
		output[2][i] = '4';
		output[3][i] = '1';
	}
	else if (str[1][index+(i * 2)] == '4' && str[1][index + (i * 2 + 8)] == '1')
	{
		output[0][i] = '1';
		output[1][i] = '2';
		output[2][i] = '3';
		output[3][i] = '4';
	}
}
