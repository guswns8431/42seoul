/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:55:59 by hyson             #+#    #+#             */
/*   Updated: 2021/07/14 16:56:04 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_mother(t_mother **m)
{
	// 여기서 선행 검사
	// 해제 <- 리스트 clear
	ft_free(&((*m)->a));
	ft_free(&((*m)->b));
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
