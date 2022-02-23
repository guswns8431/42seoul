/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:04:52 by hyson             #+#    #+#             */
/*   Updated: 2022/02/23 18:52:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->arg->fork_mutex[philo->l])
		|| !console(GRAB, philo)
		|| pthread_mutex_lock(&philo->arg->fork_mutex[philo->r])
		|| !console(GRAB, philo))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
}

void	put_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->arg->fork_mutex[philo->l])
		|| pthread_mutex_unlock(&philo->arg->fork_mutex[philo->r]))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
}

void	philo_eat(t_philo *philo)
{
	if (!console(EATING, philo)
		|| !get_time(&philo->cur))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
	++(philo->count);
	get_sleep(philo, philo->cur, philo->arg->time_eat);
	if (philo->arg->must_eat && philo->arg->must_eat == philo->count)
		if (++(philo->arg->meet) >= philo->arg->total)
			if (!console(FULL, philo))
				pthread_mutex_unlock(&philo->arg->terminate_mutex);
}

void	philo_sleep(t_philo *philo)
{
	if (!console(SLEEPING, philo))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
	get_sleep(philo, 0, philo->arg->time_sleep);
}

void	philo_think(t_philo *philo)
{
	if (!console(THINKING, philo))
		pthread_mutex_unlock(&philo->arg->terminate_mutex);
}
