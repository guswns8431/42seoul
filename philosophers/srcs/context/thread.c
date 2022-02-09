/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:36:15 by hyson             #+#    #+#             */
/*   Updated: 2022/01/26 15:28:42 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (!get_time(&philo->cur))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
	while (TRUE)
	{
		take_fork(philo);
		philo_eat(philo);
		put_fork(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)arg;
	while (TRUE)
	{
		if (!get_time(&cur))
			pthread_mutex_unlock(&philo->arg->terminate_mutex);
		if (cur - philo->cur > (long long)philo->arg->time_die)
		{
			console(DEAD, philo);
			pthread_mutex_unlock(&philo->arg->terminate_mutex);
		}
	}
	return (NULL);
}
