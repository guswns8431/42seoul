/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:13:09 by hyson             #+#    #+#             */
/*   Updated: 2021/07/01 16:14:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool create_node(t_node **node, int val)
{
	if (!ft_calloc((void **)node, 1, sizeof(t_node))
		return (false);
	(*node)->val = val;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	return (true);
}

bool	create_stack(t_stack **stack)
{
	if (!ft_calloc((void **)stack, 1, sizeof(t_stack)))
		return (false);
	(*stack)->top = NULL;
	return (true);
}
