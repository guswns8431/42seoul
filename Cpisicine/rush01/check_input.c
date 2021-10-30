/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:47:02 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 19:50:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_input(int index, char **str)
{
	i = 0;
	while (i < 4)
	{
		i++;
		if (str[1][index + (i * 2)] == '1'  && str[1][index + (i * 2 + 8)] == '2')
			continue ;
		else if (str[1][index + (i * 2)] == '2' && str[1][index + (i * 2 + 8)] == '2')
			continue ;
		else if (str[1][index + (i * 2)] == '3' && str[1][index + (i * 2 + 8)] == '2')
			continue ;
		else if (str[1][index + (i * 2)] == '4' && str[1][index + (i * 2 + 8)] == '1')
			continue ;
		else
			return (0);
		i++;
	}
	return (1)
}
