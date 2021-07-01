/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:11:34 by hyson             #+#    #+#             */
/*   Updated: 2021/07/02 05:30:29 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //빼야해
# include <stdbool.h>

typedef struct s_node
{
	int val;
	struct s_node *prev;
	struct s_node *next;
}		t_node;

typedef struct s_stack
{
	struct s_node *top;
}		t_stack;

int		ft_strcmp(char *s1, char *s2);
bool		ft_check_error(int argc, char **argv);

bool	create_stack(t_stack **stack);
bool	create_node(t_node **node, int val);
bool	insert_node(t_stack **stack, int val);
void	delete_node(t_stack **stack);


/*
** ---------------------------------------------------
** instruction
** ---------------------------------------------------
*/
void	push(t_stack **a, t_stack **b, char stack);
void	swap(t_stack **stack);

/*
** ---------------------------------------------------
** utils
** ---------------------------------------------------
*/

void	ft_memset(void *b, int c, size_t len);
bool	ft_calloc(void **tmp, size_t cnt, size_t size);

#endif
