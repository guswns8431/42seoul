/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:58:20 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 18:41:58 by hyson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iter(t_mother *m, int cnt, void (*f)(t_mother *, char *), char *cmd)
{
	int		i;

	i = -1;
	while (++i < cnt)
		f(m, cmd);
}
