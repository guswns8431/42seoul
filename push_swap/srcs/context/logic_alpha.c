/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:49 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 21:17:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_under_3(t_mother *m)
{
	if (m->a_len == 2)
	{
		if (m->a->h->v > m->a->h->n->v)
			sa(m, "sa");
	}
	else
	{
		if (m->a->h->v > m->a->h->n->v && m->a->h->n->v < m->a->h->n->n->v)
		{
			if (m->a->h->v < m->a->h->n->n->v)
				sa(m, "sa");
			if (m->a->h->v > m->a->h->n->n->v)
				ra(m, "ra");
		}
		else if (m->a->h->v < m->a->h->n->v && m->a->h->n->v > m->a->h->n->n->v)
		{
			rra(m, "rra");
			if (m->a->h->v > m->a->h->n->v)
				sa(m, "sa");
		}
		else if (m->a->h->v > m->a->h->n->v && m->a->h->n->v > m->a->h->n->n->v)
			// iter(m, 2, ra, "ra");
			ra(m, "ra");
			sa(m, "sa");
	}
}

void	sort_under_5(t_mother *m, int size)
{
	int		i;
	int		arr[5];

	find_array(m->a->h, arr, size);
	i = -1;
	while (++i < size)
	{
		if (m->a->h->v < arr[(size + 1) / 2 - 1])
			pb(m, "pb");
		else
			ra(m, "ra");
	}
	sort_under_3(m);
	if (m->b_len == 1)
		pa(m, "pa");
	else
	{
		if (m->b->h->v < m->b->h->n->v)
			sb(m, "sb");
		iter(m, 2, pa, "pa");
	}
}

void	sort_b(t_mother *m, int size)
{
	t_pivot	p;
	t_inst	i;

	ft_memset(&p, 0, sizeof(t_pivot));
	ft_memset(&i, 0, sizeof(t_inst));
	if (find_deter(m->b->h, size, is_asc))
	{
		iter(m, size, pa, "pa");
		return ;
	}
	if (size < 3)
	{
		if (size == 2 && m->b->h->v < m->b->h->n->v)
			sb(m, "sb");
		iter(m, size, pa, "pa");
		return ;
	}
	if (!find_pivot(m->b->h, &(p.p1), &(p.p2), size))
		exit_invalid(m);
	b_to_a(m, size, &p, &i);
	sort_a(m, i.pa - i.ra);
	retrieve(m, i.ra, i.rb);
	sort_a(m, i.ra);
	sort_b(m, i.rb);
}

void	sort_a(t_mother *m, int size)
{
	t_pivot	p;
	t_inst	i;

	ft_memset(&p, 0, sizeof(t_pivot));
	ft_memset(&i, 0, sizeof(t_inst));
	if (find_deter(m->a->h, size, is_dsc))
		return ;
	if (size < 3)
	{
		if (size == 2 && m->a->h->v > m->a->h->n->v)
			sa(m, "sa");
		return ;
	}
	if (!find_pivot(m->a->h, &(p.p1), &(p.p2), size))
		exit_invalid(m);
	a_to_b(m, size, &p, &i);
	retrieve(m, i.ra, i.rb);
	sort_a(m, i.ra);
	sort_b(m, i.rb);
	sort_b(m, i.pb - i.rb);
}
