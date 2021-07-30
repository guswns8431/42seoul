/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:22 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:28:23 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rrotate(t_mother *m)
{
	iter(m, 3, pb, "");
	iter(m, 2, rra, "rra");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, rrb, "rrb");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, rrr, "rrr");
	show_cw(m->a->h);
	show_cw(m->b->h);
}
