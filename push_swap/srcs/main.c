/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:59:15 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 16:59:19 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	duplicated()
{
	;
}

static bool	init(t_stack **stack)
{
	if (!ft_calloc((void **)stack, 1, sizeof(t_stack)))
		return (false);
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;
	return (true);
}

static bool	check(int argc, char **argv, t_mother *m)
{
	int			i;
	int			v;

	i = 0;
	while (++i < argc)
	{
		if (!ft_atoi(&argv[i], &v))
			return (false);
		insert_node(&(m->a), v);
	}
	return (duplicated(m->a));
}

int	main(int argc, char **argv)
{
	t_mother	m;

	ft_memset(&m, 0, sizeof(t_mother));
	if (!init(&(m.a)) || !init(&(m.b)) || check(argc, argv, &m))
		exit_invalid(&m);
	exit_valid(&m);
}
