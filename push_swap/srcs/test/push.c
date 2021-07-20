/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:59:27 by hyson             #+#    #+#             */
/*   Updated: 2021/07/20 15:35:31 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_push(t_mother *m)
{
	iter(m, 2, pb, "pb");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, pa, "pa");
	show_cw(m->a->h);
	show_cw(m->b->h);
}
