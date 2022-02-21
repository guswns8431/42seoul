/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:19:35 by hyson             #+#    #+#             */
/*   Updated: 2022/01/24 16:19:54 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void **ptr)
{
	if (!(ptr && *ptr))
		return ;
	free(*ptr);
	*ptr = NULL;
}