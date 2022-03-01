/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:36:15 by hyson             #+#    #+#             */
/*   Updated: 2022/03/01 15:49:20 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		get_sleep(philo, 0, 200);
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
	get_sleep(philo, 0, philo->arg->time_die - 10);
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

void	get_sleep(t_philo *philo, long long start, long long limit)
{
	long long	current;

	current = 0;
	if (!start)
		if (!get_time(&start))
			pthread_mutex_unlock(&philo->arg->terminate_mutex);
	while (TRUE)
	{
		if (!get_time(&current))
			pthread_mutex_unlock(&philo->arg->terminate_mutex);
		if (current - start >= limit)
			break ;
		if (usleep(200) == ERROR)
			pthread_mutex_unlock(&philo->arg->terminate_mutex);
	}
}
