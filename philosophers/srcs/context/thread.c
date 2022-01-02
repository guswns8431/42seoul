/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:36:15 by hyson             #+#    #+#             */
/*   Updated: 2021/12/29 17:59:17 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int i = 0;
	t_philo *philo;

	philo = (t_philo *)arg;
	while (++i < 10)
		printf("%d %d %d\n", philo->l, philo->r, i);
	return (NULL);
}
