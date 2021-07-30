/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:33 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:28:35 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_rotate(t_mother *m)
{
	iter(m, 3, pb, "");
	iter(m, 2, ra, "ra");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, rb, "rb");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, rr, "rr");
	show_cw(m->a->h);
	show_cw(m->b->h);
}
