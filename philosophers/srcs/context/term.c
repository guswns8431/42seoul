/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:37:30 by hyson             #+#    #+#             */
/*   Updated: 2022/01/24 16:25:10 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_arg(t_arg *arg, t_philo **philo)
{
	int		i;

	i = -1;
	if (arg->fork_mutex)
		while (++i < arg->total)
			pthread_mutex_destroy(&arg->fork_mutex[i]);
	ft_free((void **)(&arg->fork_mutex));
	ft_free((void **)(philo));
	pthread_mutex_destroy(&arg->terminate_mutex);
	pthread_mutex_destroy(&arg->print_mutex);
}

void	exit_invalid_arg(void)
{
	errno = 22;
	perror("arg");
}

t_bool	exit_invalid(t_arg *arg, t_philo **philo)
{
	free_arg(arg, philo);
	return (INVALID);
}

t_bool	exit_valid(t_arg *arg, t_philo **philo)
{
	free_arg(arg, philo);
	return (VALID);
}
