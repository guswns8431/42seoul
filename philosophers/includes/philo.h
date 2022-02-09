/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:58:29 by hyson             #+#    #+#             */
/*   Updated: 2022/01/24 16:24:53 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define MILLI 1000
# define VALID 0
# define INVALID 1

typedef int		t_bool;
typedef pthread_t	t_th;
typedef pthread_mutex_t	t_mu;

typedef enum e_state
{
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL,
}					t_state;

typedef struct		s_arg {
	int		total;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		time_limit;
	int		meet;
	t_mu		print_mutex;
	t_mu		*fork_mutex;
	t_mu		terminate_mutex;
	long long	start_time;
}			t_arg;

typedef struct		s_philo {
	int		id;
	int 		l;
	int 		r;
	int		count;
	t_arg		*arg;
	t_th		th;
	t_th		mo;
	long long		cur;
}			t_philo;

/*
** -----------------------------------------------------------------------------
** C O N T E X T
** -----------------------------------------------------------------------------
*/

void		exit_invalid_arg(void);
t_bool		exit_invalid(t_arg *arg, t_philo **philo);
t_bool		exit_valid(t_arg *arg, t_philo **philo);
void		*routine(void *arg);
void		*monitor(void *arg);
t_bool		console(int state, t_philo *philo);
void		take_fork(t_philo *philo);
void		philo_eat(t_philo *philo);
void		put_fork(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
t_bool		get_time(long long *time);

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
t_bool		ft_isspace(int c);
t_bool		ft_calloc(void **ptr, size_t cnt, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_free(void **ptr);

#endif
