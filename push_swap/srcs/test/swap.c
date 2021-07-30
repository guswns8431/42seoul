/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:10 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:28:15 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_swap(t_mother *m)
{
	iter(m, 2, pb, "");
	iter(m, 1, sa, "sa");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 1, sb, "sb");
	show_cw(m->a->h);
	show_cw(m->b->h);
	ft_putchar_fd('\n', STDOUT_FILENO);
	iter(m, 2, ss, "ss");
	show_cw(m->a->h);
	show_cw(m->b->h);
}
