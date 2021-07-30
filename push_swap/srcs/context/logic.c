/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:28:49 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:41:41 by hyson            ###   ########.fr       */
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
			iter(m, 2, ra, "ra");
	}
}

static void	find_median(t_node *tmp, int arr[5], int size)
{
	int		i;
	int		j;
	int		v;

	i = -1;
	while (tmp)
	{
		arr[++i] = tmp->v;
		tmp = tmp->n;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				v = arr[i];
				arr[i] = arr[j];
				arr[j] = v;
			}
		}
	}
}

void	sort_under_5(t_mother *m, int size)
{
	int		i;
	int		arr[5];

	find_median(m->a->h, arr, size);
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

void	b_to_a(t_mother *m)
{
	m = NULL;
}

void	a_to_b(t_mother *m)
{
	m = NULL;
}
