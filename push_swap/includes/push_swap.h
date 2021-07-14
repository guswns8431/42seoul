/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:27 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 16:55:33 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef enum e_exit
{
	VALID,
	INVALID,
}					t_exit;

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

typedef struct s_mother
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_mother;

/*
** -----------------------------------------------------------------------------
** context
** -----------------------------------------------------------------------------
*/

void	exit_invalid(t_mother *m);
void	exit_valid(t_mother *m);

/*
** -----------------------------------------------------------------------------
** ft functions
** -----------------------------------------------------------------------------
*/

bool	ft_atoi(char **s, int *v);
bool	ft_calloc(void **tmp, size_t cnt, size_t size);
void	ft_free(void **ptr);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlen(const char *s);

/*
** -----------------------------------------------------------------------------
** instruction
** -----------------------------------------------------------------------------
*/

void	iter(t_mother **m, int cnt, void (*f)(t_mother **, char *), char *cmd);
void	pa(t_mother **m, char *s);
void	pb(t_mother **m, char *s);
void	ra(t_mother **m, char *s);
void	rb(t_mother **m, char *s);
void	rr(t_mother **m, char *s);
void	rra(t_mother **m, char *s);
void	rrb(t_mother **m, char *s);
void	rrr(t_mother **m, char *s);
void	sa(t_mother **m, char *s);
void	sb(t_mother **m, char *s);
void	ss(t_mother **m, char *s);

/*
** -----------------------------------------------------------------------------
** test
** -----------------------------------------------------------------------------
*/

void	test_push(t_mother **m);
void	test_rotate(t_mother **m);
void	test_rrotate(t_mother **m);
void	test_swap(t_mother **m);

#endif
