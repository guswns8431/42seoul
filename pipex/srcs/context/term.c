/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:46:17 by hyson             #+#    #+#             */
/*   Updated: 2021/09/28 16:51:34 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_invalid()
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(INVALID);
}

void	exit_valid()
{
	exit(VALID);
}
