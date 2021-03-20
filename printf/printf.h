/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:57:57 by hyson             #+#    #+#             */
/*   Updated: 2021/03/20 16:39:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct {
	int minus;
	int zero;
	int width;
	int dot;
	int precision;
}			t_option

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_check_option_type(const char *format, va_list ap);
void	ft_check_type(char *str);
int		ft_is_type(char c);
void	*ft_memset(void *b, int c, size_t len);

#endif
