/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 06:14:33 by hyson             #+#    #+#             */
/*   Updated: 2021/07/08 23:22:38 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_node *tmp;

	if ((*stack)->top == (*stack)->bottom)
		return ;
	tmp = (*stack)->bottom;
	(*stack)->bottom = (*stack)->top;
	(*stack)->bottom->next = tmp;
	(*stack)->top = (*stack)->bottom->prev;
	(*stack)->top->next = NULL;
	(*stack)->top->prev = (*stack)->bottom->prev->prev;
	(*stack)->bottom->prev = NULL;
}
