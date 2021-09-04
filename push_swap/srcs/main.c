/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:09:10 by hyson             #+#    #+#             */
/*   Updated: 2021/09/04 16:33:01 by hyson            ###   ########.fr       */
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

static t_node	**parse(char *argv, t_node **tmp, t_mother *m)
{
	int			v;
	t_node		**end;

	if (!argv || !*argv)
		return (NULL);
	while (*argv)
	{
		while (ft_isspace(*argv))
			++argv;
		if (!ft_atoi(&argv, &v) || !insert(tmp, v))
			return (NULL);
		++(m->a_len);
		end = tmp;
		tmp = &((*tmp)->n);
	}
	return (end);
}

static bool	check(int argc, char **argv, t_mother *m)
{
	int			i;
	t_node		**tmp;

	i = 0;
	tmp = &(m->a->h);
	while (++i < argc)
	{
		tmp = parse(argv[i], tmp, m);
		if (!tmp)
			return (false);
		tmp = &((*tmp)->n);
	}
	return (!duplicated(m->a->h));
}

static bool	connect(t_stack *stack)
{
	bool		asc;
	t_node		*cur;
	t_node		*next;

	asc = false;
	cur = stack->h;
	next = cur->n;
	while (cur && next)
	{
		if (cur->v > next->v)
			asc = true;
		next->p = cur;
		cur = next;
		next = next->n;
	}
	stack->t = cur;
	return (asc);
}

int	main(int argc, char **argv)
{
	t_mother	m;

	ft_memset(&m, 0, sizeof(t_mother));
	if (!init(&(m.a)) || !init(&(m.b)) || !check(argc, argv, &m))
		exit_invalid(&m);
	if (m.a_len <= 1 || !connect(m.a))
		exit_valid(&m);
	else if (m.a_len <= 3)
		sort_under_3(&m);
	else if (m.a_len <= 5)
		sort_under_5(&m, m.a_len);
	else
		sort_a(&m, m.a_len);
	exit_valid(&m);
}
