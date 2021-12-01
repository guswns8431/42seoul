/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:29 by hyson             #+#    #+#             */
/*   Updated: 2021/12/01 20:48:32 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>

/*
** -----------------------------------------------------------------------------
** T E R M I N A T I O N
** -----------------------------------------------------------------------------
*/

void	exit_invalid_arg(void);
void	exit_valid(void);

/*
** -----------------------------------------------------------------------------
** F T _ F U N C T I O N
** -----------------------------------------------------------------------------
*/

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
