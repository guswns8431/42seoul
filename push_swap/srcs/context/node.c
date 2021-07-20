/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:07:08 by hyson             #+#    #+#             */
/*   Updated: 2021/07/20 15:07:12 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	insert(t_node **node, int v)
{
	if (!ft_calloc((void **)(node), 1, sizeof(t_node)))
		return (false);
	(*node)->v = v;
	return (true);
}

void	show_cw(t_node *node)
{
	while (node)
	{
		ft_putnbr_fd(node->v, STDOUT_FILENO);
		ft_putendl_fd("", STDOUT_FILENO);
		node = node->n;
	}
}

void	show_ccw(t_node *node)
{
	while (node)
	{
		ft_putnbr_fd(node->v, STDOUT_FILENO);
		ft_putendl_fd("", STDOUT_FILENO);
		node = node->p;
	}
}

void	clear(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->n;
		ft_free((void **)(&node));
		node = tmp;
	}
}
