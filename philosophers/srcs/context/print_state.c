/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:30 by hyson             #+#    #+#             */
/*   Updated: 2022/02/23 16:50:11 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_state(int state)
{
	if (state == DEAD)
		ft_putstr_fd(" died\n", STDOUT_FILENO);
	else if (state == GRAB)
		ft_putstr_fd(" has taken a fork\n", STDOUT_FILENO);
	else if (state == EATING)
		ft_putstr_fd(" is eating\n", STDOUT_FILENO);
	else if (state == SLEEPING)
		ft_putstr_fd(" is sleeping\n", STDOUT_FILENO);
	else if (state == THINKING)
		ft_putstr_fd(" is thinking\n", STDOUT_FILENO);
	else if (state == FULL)
		ft_putstr_fd("Finished\n", STDOUT_FILENO);
}

t_bool	console(int state, t_philo *philo)
{
	long long	current_time;

	if (pthread_mutex_lock(&philo->arg->print_mutex)
		|| !get_time(&current_time))
		return (FALSE);
	ft_putnbr_fd(current_time - philo->arg->start_time, STDOUT_FILENO);
	ft_putstr_fd("\t", STDOUT_FILENO);
	if (state == FULL || state == DEAD)
	{
		if (state == DEAD)
			ft_putnbr_fd(philo->id + 1, STDOUT_FILENO);
		print_state(state);
		return (FALSE);
	}
	ft_putnbr_fd(philo->id + 1, STDOUT_FILENO);
	print_state(state);
	if (pthread_mutex_unlock(&philo->arg->print_mutex))
		return (FALSE);
	return (TRUE);
}
