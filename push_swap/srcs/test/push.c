/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:38 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:28:39 by hyson            ###   ########.fr       */
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
