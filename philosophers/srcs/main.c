/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:30:41 by hyson             #+#    #+#             */
/*   Updated: 2021/12/22 16:26:56 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_init(int argc, char **argv, t_arg *args)
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
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_arg args;

	ft_memset(&args, 0, sizeof(t_arg));
	if (argc != 5 && argc != 6)
	{
		exit_invalid_arg();
		return (ERROR);
	}
	//초기화
	if (!philo_init(argc, argv, &args))
	{
		exit_invalid_arg();
		return (ERROR);
	}
	//초기화 유효성 검증
	//철학자 쓰레드 생성
	printf("%d %d %d %d %d\n", args.total, args.time_die, args.time_eat, args.time_sleep, args.time_limit);
	return (0);
}
