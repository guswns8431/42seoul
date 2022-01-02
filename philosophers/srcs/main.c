/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:30:41 by hyson             #+#    #+#             */
/*   Updated: 2021/12/29 18:01:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_th(t_arg args, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < args.total)
	{
		philo[i].arg = &args;
		philo[i].l = i; //test
		philo[i].r = i; //test
		if (pthread_create(&philo[i].th, NULL, routine, (void *)(&philo[i])) || pthread_join(philo[i].th, NULL))
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	philo_init(int argc, char **argv, t_arg *args, t_philo **philo)
{
	if (!ft_atoi(argv[1], &args->total) || !ft_atoi(argv[2], &args->time_die)
		|| !ft_atoi(argv[3], &args->time_eat)
		|| !ft_atoi(argv[4], &args->time_sleep))
		return (FALSE);
	if (argc == 6 && !ft_atoi(argv[5], &args->time_limit))
		return (FALSE);
	if (args->total < 0 || args->time_die < 0 || args->time_eat < 0
		|| args->time_sleep < 0 || args->time_limit < 0)
		return (FALSE);
	if (!ft_calloc((void **)philo, args->total, sizeof(t_philo)))
		return (FALSE);
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_arg args;
	t_philo *philo;

	philo = NULL;
	ft_memset(&args, 0, sizeof(t_arg));
	if (argc != 5 && argc != 6)
	{
		exit_invalid_arg();
		return (ERROR);
	}
	//초기화
	//초기화 유효성 검증
	if (!philo_init(argc, argv, &args, &philo))
	{
		exit_invalid_arg();
		return (ERROR);
	}
	//철학자 쓰레드 생성
	philo_th(args, philo);
	printf("%d %d %d %d %d\n", args.total, args.time_die, args.time_eat, args.time_sleep, args.time_limit);
	return (0);
}
