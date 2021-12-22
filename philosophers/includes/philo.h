/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:29 by hyson             #+#    #+#             */
/*   Updated: 2021/12/22 15:28:25 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct	s_arg {
	int	total;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	time_limit;
}		t_arg;

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

size_t		ft_strlen(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		*ft_memset(void *b, int c, size_t len);
t_bool		ft_atoi(const char *str, int *result);
int			ft_isdigit(int c);

#endif
