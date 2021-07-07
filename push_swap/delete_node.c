/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:46:00 by hyson             #+#    #+#             */
/*   Updated: 2021/07/07 15:19:39 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_stack **stack)
{
	t_node *tmp;

	write(1, "test3\n", 6);
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->prev;
	if ((*stack)->top == NULL)
		(*stack)->bottom = NULL;
	//(*stack)->top->next = NULL;
	write(1, "test4\n", 6);
	free(tmp);
}
