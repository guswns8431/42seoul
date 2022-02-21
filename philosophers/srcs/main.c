/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:30:41 by hyson             #+#    #+#             */
/*   Updated: 2022/02/21 17:50:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_th(t_arg *args, t_philo *philo)
{
	int	i;

	i = -1;
	if (pthread_mutex_lock(&args->terminate_mutex)
		|| !get_time(&args->start_time))
		return (FALSE);
	while (++i < args->total)
	{
		philo[i].id = i;
		philo[i].arg = args;
		philo[i].l = i;
		philo[i].r = (i + 1) % args->total;
		if (pthread_create(&philo[i].th, NULL, routine, (void *)(&philo[i]))
			|| pthread_detach(philo[i].th))
			return (FALSE);
		if (pthread_create(&philo[i].mo, NULL, monitor, (void *)(&philo[i]))
			|| pthread_detach(philo[i].mo))
			return (FALSE);
	}
	if (pthread_mutex_lock(&args->terminate_mutex))
		return (FALSE);
	return (TRUE);
}

static t_bool	philo_init(int argc, char **argv, t_arg *args, t_philo **philo)
{
	int	i;

	i = -1;
	if (!ft_atoi(argv[1], &args->total)
		|| !ft_atoi(argv[2], &args->time_die)
		|| !ft_atoi(argv[3], &args->time_eat)
		|| !ft_atoi(argv[4], &args->time_sleep))
		return (FALSE);
	if (argc == 6 && !ft_atoi(argv[5], &args->time_limit))
		return (FALSE);
	if (args->total < 0 || args->time_die < 0 || args->time_eat < 0
		|| args->time_sleep < 0 || args->time_limit < 0)
		return (FALSE);
	if (!ft_calloc((void **)(philo), args->total, sizeof(t_philo))
		|| !ft_calloc((void **)(&args->fork_mutex), args->total, sizeof(t_mu)))
		return (FALSE);
	while (++i < args->total)
		if (pthread_mutex_init(&args->fork_mutex[i], NULL))
			return (FALSE);
	if (pthread_mutex_init(&args->print_mutex, NULL)
		|| pthread_mutex_init(&args->terminate_mutex, NULL))
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_arg	args;
	t_philo	*philo;

	ft_memset(&args, 0, sizeof(t_arg));
	if (argc != 5 && argc != 6)
	{
		exit_invalid_arg();
		return (ERROR);
	}
	if (!philo_init(argc, argv, &args, &philo))
	{
		exit_invalid_arg();
		return (ERROR);
	}
	if (!philo_th(&args, philo))
		return (exit_invalid(&args, &philo));
	return (exit_valid(&args, &philo));
}
