/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:30:59 by hyson             #+#    #+#             */
/*   Updated: 2022/01/12 17:48:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	get_time(long long *time)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == ERROR)
		return (FALSE);
	*time = (long long)(tv.tv_sec * MILLI + tv.tv_usec / MILLI);
	return (TRUE);
}
