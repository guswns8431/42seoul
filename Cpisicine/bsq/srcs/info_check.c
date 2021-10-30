/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:47:00 by hyson             #+#    #+#             */
/*   Updated: 2020/12/10 06:47:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	symbol_is_same(t_map *nh_map)
{
	if (nh_map->obstacle == nh_map->blank)
		return (0);
	if (nh_map->obstacle == nh_map->full)
		return (0);
	if (nh_map->blank == nh_map->full)
		return (0);
	return (1);
}

int	symbol_is_non_printable(t_map *nh_map)
{
	if ((nh_map->obstacle <= 31) || (nh_map->obstacle > 126))
		return (0);
	if ((nh_map->full <= 31) || (nh_map->full > 126))
		return (0);
	if ((nh_map->blank <= 31) || (nh_map->blank > 126))
		return (0);
	return (1);
}

int	is_number(char nb)
{
	return (nb >= '0' && nb <= '9');
}
