/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:40:47 by hyson             #+#    #+#             */
/*   Updated: 2021/07/05 17:23:59 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, char stack)
{
	if (stack == 'a')
	{
		if ((*b)->top == NULL)
			return ;
		if ((*b)->top == (*b)->bottom)
			(*b)->bottom = NULL;
		if (!insert_node(a, (*b)->top->val))
			return ;
		delete_node(b);
	}
	else if (stack == 'b')
	{
		write(1, "test1\n", 6);
		if ((*a)->top == NULL)
			return ;
		if ((*a)->top == (*a)->bottom)
			(*a)->bottom = NULL;
		if (!insert_node(b, (*a)->top->val))
			return ;
		write(1, "test2\n", 6);
		delete_node(a);
	}
}
