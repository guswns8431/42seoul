/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_beta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:55:44 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 21:18:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retrieve(t_mother *m, int ra, int rb)
{
	int		cnt;

	cnt = ra;
	if (ra > rb)
		cnt = rb;
	iter(m, cnt, rrr, "rrr");
	if (ra > rb)
		iter(m, ra - cnt, rra, "rra");
	else
		iter(m, rb - cnt, rrb, "rrb");
}

void	b_to_a(t_mother *m, int size, t_pivot *p, t_inst *i)
{
	while (size--)
	{
		if (m->b->h->v < p->p1)
		{
			rb(m, "rb");
			++(i->rb);
		}
		else
		{
			pa(m, "pa");
			++(i->pa);
			if (m->a->h->v < p->p2)
			{
				ra(m, "ra");
				++(i->ra);
			}
		}
	}
}

void	a_to_b(t_mother *m, int size, t_pivot *p, t_inst *i)
{
	while (size--)
	{
		if (m->a->h->v >= p->p2)
		{
			ra(m, "ra");
			++(i->ra);
		}
		else
		{
			pb(m, "pb");
			++(i->pb);
			if (m->b->h->v >= p->p1)
			{
				rb(m, "rb");
				++(i->rb);
			}
		}
	}
}
