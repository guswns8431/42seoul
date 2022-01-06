/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:36:15 by hyson             #+#    #+#             */
/*   Updated: 2022/01/03 16:35:57 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int i = 0;
	t_philo *philo;
	t_th tid;

	tid = pthread_self();
	philo = (t_philo *)arg;
	while (++i < 20)
		printf("thread : %x %d %d %d\n", (unsigned int)tid, philo->l, philo->r, i);
	return (NULL);
}
