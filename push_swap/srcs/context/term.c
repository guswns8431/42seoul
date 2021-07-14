/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:59 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 18:44:50 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_mother(t_mother **m)
{
	// clear((*m)->a->h);
	// clear((*m)->b->h);
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
