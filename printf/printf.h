/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:57:57 by hyson             #+#    #+#             */
/*   Updated: 2021/03/25 19:08:44 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct
{
	int minus;
	int zero;
	int width;
	int dot;
	int precision;
}		t_option;

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_check_option_type(char **format, va_list ap);
void	ft_check_type(char *c, t_option *val, va_list ap);
int		ft_is_type(char *c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_check_option(t_option *val, char *c);
void	ft_print_type_c(t_option *val, va_list ap);
void	ft_print_type_s(t_option *val, va_list ap);
int		ft_process_precision(int len, int precision);
void	ft_process_width(int len, int precision);
int	ft_atoi(char **str);

#endif
