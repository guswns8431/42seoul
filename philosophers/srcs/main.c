/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:30:41 by hyson             #+#    #+#             */
/*   Updated: 2021/12/01 20:49:41 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		exit_invalid_arg();
		return (1);
	}
	printf("%s\n", argv[1]);
	return (0);
}