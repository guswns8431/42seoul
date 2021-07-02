/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:26:19 by hyson             #+#    #+#             */
/*   Updated: 2021/07/02 15:27:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	insert_node(t_stack **stack, int val)
{
	t_node *new;
	if (!ft_calloc((void **)&new, 1, sizeof(t_node)))
		return (false);
	if ((*stack)->bottom == NULL)
		(*stack)->bottom = new;
	new->prev = (*stack)->top;
	(*stack)->top = new;
	new->next = NULL;
	new->val = val;
	return (true);
}
