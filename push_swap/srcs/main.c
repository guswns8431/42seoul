/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:59:15 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 18:41:45 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	duplicated(t_node *node)
{
	t_node		*tmp;

	while (node)
	{
		if (node->n)
		{
			tmp = node->n;
			while (tmp)
			{
				if (node->v == tmp->v)
					return (true);
				tmp = tmp->n;
			}
		}
		node = node->n;
	}
	return (false);
}

static bool	init(t_stack **stack)
{
	if (!ft_calloc((void **)stack, 1, sizeof(t_stack)))
		return (false);
	(*stack)->h = NULL;
	(*stack)->t = NULL;
	return (true);
}

static bool	check(int argc, char **argv, t_mother *m)
{
	int			i;
	int			v;
	t_node		**tmp;

	i = 0;
	tmp = &(m->a->h);
	while (++i < argc)
	{
		if (!ft_atoi(&argv[i], &v) || !insert(tmp, v))
			return (false);
		tmp = &((*tmp)->n);
	}
	return (!duplicated(m->a->h));
}

static void	connect(t_stack *stack)
{
	t_node		*cur;
	t_node		*next;

	cur = stack->h;
	next = cur->n;
	while (cur && next)
	{
		next->p = cur;
		cur = next;
		next = next->n;
	}
	stack->t = cur;
}

int	main(int argc, char **argv)
{
	t_mother	m;

	ft_memset(&m, 0, sizeof(t_mother));
	if (!init(&(m.a)) || !init(&(m.b)) || !check(argc, argv, &m))
		exit_invalid(&m);
	connect(m.a);
	test_push(&m);
	// logic(&m);
	exit_valid(&m);
}
