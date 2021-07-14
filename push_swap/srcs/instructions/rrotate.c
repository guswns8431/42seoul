/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:58:40 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 19:13:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_mother *m, char *s)
{
	t_node	*tmp;

	if (m->a->h == m->a->t)
		return ;
	tmp = m->a->t;
	m->a->t = m->a->t->p;
	m->a->t->n = NULL;
	m->a->h->p = tmp;
	tmp->p = NULL;
	tmp->n = m->a->h;
	m->a->h = tmp;
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	rrb(t_mother *m, char *s)
{
	t_node	*tmp;

	if (m->b->h == m->b->t)
		return ;
	tmp = m->b->t;
	m->b->t = m->b->t->p;
	m->b->t->n = NULL;
	m->b->h->p = tmp;
	tmp->p = NULL;
	tmp->n = m->b->h;
	m->b->h = tmp;
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	rrr(t_mother *m, char *s)
{
	rra(m, "");
	rrb(m, "");
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}
