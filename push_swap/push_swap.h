/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:11:34 by hyson             #+#    #+#             */
/*   Updated: 2021/06/30 21:40:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //빼야해
# include <stdbool.h>

typedef struct node
{
	int data;
	struct node *pre;
	struct node *next;
}		t_node;

typedef struct stack
{
	struct node *top;
}		t_stack;

int		ft_strcmp(char *s1, char *s2);
bool		ft_check_error(int argc, char **argv);

t_stack	*create_stack(void);

#endif
