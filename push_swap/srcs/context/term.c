/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:30:31 by hyson             #+#    #+#             */
/*   Updated: 2021/07/30 14:33:18 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_mother(t_mother **m)
{
	clear((*m)->a->h);
	clear((*m)->b->h);
	ft_free((void **)(&((*m)->a)));
	ft_free((void **)(&((*m)->b)));
}

void	exit_invalid(t_mother *m)
{
	free_mother(&m);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(INVALID);
}

void	exit_valid(t_mother *m)
{
	free_mother(&m);
	exit(VALID);
}
