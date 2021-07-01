/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 05:02:12 by hyson             #+#    #+#             */
/*   Updated: 2021/07/02 05:44:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if ((*stack)->top->prev == NULL || (*stack)->top == NULL)
		return ;
	(*stack)->top->next = (*stack)->top->prev;
	(*stack)->top->prev = (*stack)->top->prev->prev;
	(*stack)->top->next->next = NULL;
	(*stack)->top->next->prev = (*stack)->top;
	(*stack)->top->prev->next = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
}
