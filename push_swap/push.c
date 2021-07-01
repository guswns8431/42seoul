/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:40:47 by hyson             #+#    #+#             */
/*   Updated: 2021/07/02 02:13:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, char stack)
{
	t_node *tmp;

	if (stack == 'a')
	{
		tmp = (*b)->top->prev;
		(*a)->top->next = (*b)->top;
		(*b)->top->prev = (*a)->top;
		(*a)->top = (*b)->top;
		(*b)->top = tmp;
		(*b)->top->next = NULL;
	}
	else if (stack == 'b')
	{
		tmp = (*a)->top->prev;
		(*b)->top->next = (*a)->top;
		(*a)->top->prev = (*b)->top;
		(*b)->top = (*a)->top;
		(*a)->top = tmp;
		(*a)->top->next = NULL;
	}
}
