/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:46:17 by hyson             #+#    #+#             */
/*   Updated: 2021/11/29 11:04:49 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_invalid(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(INVALID);
}

void	exit_valid(void)
{
	exit(VALID);
}
