/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:11:34 by hyson             #+#    #+#             */
/*   Updated: 2021/07/01 16:04:33 by hyson            ###   ########.fr       */
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
	int val;
	struct node *prev;
	struct node *next;
}		t_node;

typedef struct stack
{
	struct node *top;
}		t_stack;

int		ft_strcmp(char *s1, char *s2);
bool		ft_check_error(int argc, char **argv);

bool	create_stack(void);
bool	create_node(t_node **node, int val);

/*
** -----------------------------------------------
** utils
** -----------------------------------------------
*/

void	ft_memset(void *b, int c, size_t len);
bool	ft_calloc(void **tmp, size_t cnt, size_t size);

#endif
