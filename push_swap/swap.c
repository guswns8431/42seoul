/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 05:02:12 by hyson             #+#    #+#             */
/*   Updated: 2021/07/07 21:47:43 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_node *tmp;

	if ((*stack)->top->prev == NULL || (*stack)->top == NULL)
		return ;
	if ((*stack)->top->prev == (*stack)->bottom) //2개 있을때
	{
		tmp = (*stack)->top;
		(*stack)->top = (*stack)->bottom;
		(*stack)->top->prev = tmp;
		(*stack)->top->next = NULL;
		(*stack)->bottom = tmp;
		(*stack)->bottom->next = (*stack)->top;
		(*stack)->bottom->prev = NULL;
		return ;
	}
	(*stack)->top->next = (*stack)->top->prev;
	(*stack)->top->prev = (*stack)->top->prev->prev;
	(*stack)->top->next->next = NULL;
	(*stack)->top->next->prev = (*stack)->top;
	(*stack)->top->prev->next = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
}
