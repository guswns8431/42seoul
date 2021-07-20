/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:58:45 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 19:44:00 by hyson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_mother *m, char *s)
{
	t_node	*tmp;

	if (!m->a->h || !m->a->h->n)
		return ;
	tmp = m->a->h->n;
	if (m->a->h->n->n)
	{
		m->a->h->n->n->p = m->a->h;
		m->a->h->p = tmp;
		m->a->h->n = m->a->h->n->n;
		tmp->p = NULL;
		tmp->n = m->a->h;
		m->a->h = tmp;
	}
	else
	{
		m->a->t = m->a->h;
		m->a->h = tmp;
		m->a->h->p = NULL;
		m->a->h->n = m->a->t;
		m->a->t->p = m->a->h;
		m->a->t->n = NULL;
	}
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	sb(t_mother *m, char *s)
{
	t_node	*tmp;

	if (!m->b->h || !m->b->h->n)
		return ;
	tmp = m->b->h->n;
	if (m->b->h->n->n)
	{
		m->b->h->n->n->p = m->b->h;
		m->b->h->p = tmp;
		m->b->h->n = m->b->h->n->n;
		tmp->p = NULL;
		tmp->n = m->b->h;
		m->b->h = tmp;
	}
	else
	{
		m->b->t = m->b->h;
		m->b->h = tmp;
		m->b->h->p = NULL;
		m->b->h->n = m->b->t;
		m->b->t->p = m->b->h;
		m->b->t->n = NULL;
	}
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	ss(t_mother *m, char *s)
{
	sa(m, "");
	sb(m, "");
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}
