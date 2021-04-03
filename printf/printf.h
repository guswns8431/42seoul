/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:57:57 by hyson             #+#    #+#             */
/*   Updated: 2021/04/03 20:06:00 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
int		ft_nbrlen(long long nbr, int base);
void	ft_check_option_type(char **format, va_list ap);
void	ft_check_type(char *c, t_option *val, va_list ap);
int		ft_is_type(char *c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_check_option(t_option *val, char **c);
void	ft_print_type_c(t_option *val, va_list ap);
void	ft_print_type_s(t_option *val, va_list ap);
int		ft_process_precision(int len, int precision);
void	ft_process_width(int len, int precision, int zero, int dot);
int		ft_atoi(char **str);
void	ft_print_type_d(t_option *val, va_list ap);
void	ft_print_type_u(t_option *val, va_list ap);
void	ft_putnbr_base(long long nb, char *base);
void	ft_process_precision_num(int precision, int len);
void	ft_print_type_upx(t_option *val, va_list ap);
void	ft_print_type_lowx(t_option *val, va_list ap);
void	ft_print_type_p(t_option *val, va_list ap);

#endif
