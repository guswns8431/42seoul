/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:44:33 by hyson             #+#    #+#             */
/*   Updated: 2021/07/12 16:10:36 by hyson            ###   ########.fr       */
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
	(*stack)->top->next = NULL;
	(*stack)->top->prev = tmp;
	(*stack)->bottom = (*stack)->top->prev;
	(*stack)->bottom->next = (*stack)->top->prev->prev;
	(*stack)->bottom->prev = NULL;
}
