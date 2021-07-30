/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:31:04 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 15:51:32 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	export(t_node **node, t_node **head, t_node **tail)
{
	(*head) = (*head)->n;
	if (!*head)
		*tail = NULL;
	else
		(*head)->p = NULL;
	(*node)->p = NULL;
	(*node)->n = NULL;
}

static void	import(t_node **node, t_node **head, t_node **tail)
{
	if (!*head)
	{
		*head = *node;
		*tail = *node;
	}
	else
	{
		(*head)->p = *node;
		(*node)->n = *head;
		*head = *node;
	}
}

void	pa(t_mother *m, char *s)
{
	t_node	*tmp;

	if (!m->b->h)
		return ;
	tmp = m->b->h;
	export(&tmp, &(m->b->h), &(m->b->t));
	import(&tmp, &(m->a->h), &(m->a->t));
	if (s)
		ft_putendl_fd(s, STDOUT_FILENO);
	++(m->a_len);
	--(m->b_len);
}

void	pb(t_mother *m, char *s)
{
	t_node	*tmp;

	if (!m->a->h)
		return ;
	tmp = m->a->h;
	export(&tmp, &(m->a->h), &(m->a->t));
	import(&tmp, &(m->b->h), &(m->b->t));
	if (s)
		ft_putendl_fd(s, STDOUT_FILENO);
	--(m->a_len);
	++(m->b_len);
}
