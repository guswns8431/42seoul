/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4321.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:29:51 by hyson             #+#    #+#             */
/*   Updated: 2020/11/29 17:01:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_index_0(char *preset);
int		check_index_8(char *preset);
int		check_index_16(char *preset);
int		check_index_24(char *preset);

void	set_preset(char *preset)
{
	preset[0] = '1';
	preset[1] = '2';
	preset[2] = '3';
	preset[3] = '4';
}

int		check_4321(char **str)
{
	int		i;
	int		j;
	char	preset[4];

	set_preset(preset);
	if (check_index_0(preset) != 1)
		return (check_index_0(preset));
	set_preset(preset);
	if (check_index_8(preset) != 1)
		return (check_index_8(preset));
	set_preset(preset);
	if (check_index_16(preset) != 1)
		return (check_index_16(preset));
	set_preset(preset);
	if (check_index_24(preset) != 1)
		return (check_index_24(preset));
	return (1);
}
