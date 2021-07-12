/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:44:33 by hyson             #+#    #+#             */
/*   Updated: 2021/07/12 23:58:16 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_node *tmp;

	if ((*stack)->top == (*stack)->bottom)
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->bottom;
	(*stack)->top->prev = tmp;
	tmp->next = (*stack)->bottom;
	(*stack)->bottom = (*stack)->top->next;
	(*stack)->bottom->prev = NULL;
	write(1, "test7\n", 6);
	(*stack)->bottom->next = (*stack)->top->next->next;
	write(1, "test8\n", 6);
	(*stack)->top->next = NULL;
	write(1, "test9\n", 6);
}
