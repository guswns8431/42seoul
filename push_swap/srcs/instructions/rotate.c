/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:58:29 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 19:03:33 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_mother *m, char *s)
{
	t_node	*tmp;

	if (m->a->h == m->a->t)
		return ;
	tmp = m->a->h;
	m->a->h = m->a->h->n;
	m->a->h->p = NULL;
	m->a->t->n = tmp;
	tmp->p = m->a->t;
	tmp->n = NULL;
	m->a->t = tmp;
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	rb(t_mother *m, char *s)
{
	t_node	*tmp;

	if (m->b->h == m->b->t)
		return ;
	tmp = m->b->h;
	m->b->h = m->b->h->n;
	m->b->h->p = NULL;
	m->b->t->n = tmp;
	tmp->p = m->b->t;
	tmp->n = NULL;
	m->b->t = tmp;
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}

void	rr(t_mother *m, char *s)
{
	ra(m, "");
	rb(m, "");
	if (*s)
		ft_putendl_fd(s, STDOUT_FILENO);
}
