/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:46:00 by hyson             #+#    #+#             */
/*   Updated: 2021/07/02 10:46:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_stack **stack)
{
	t_node *tmp;

	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->prev;
	if ((*stack)->top == NULL)
		(*stack)->bottom = NULL;
	(*stack)->top->next = NULL;
	free(tmp);
}
