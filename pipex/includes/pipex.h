/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:57:57 by hyson             #+#    #+#             */
/*   Updated: 2021/09/13 20:00:03 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

/*
** -----------------------------------------------------------------------------
**							F T _ F U N C T I O N S								
** -----------------------------------------------------------------------------
*/

bool	ft_atoi(char **s, int *v);
bool	ft_calloc(void **tmp, size_t cnt, size_t size);
void	ft_free(void **ptr);
bool	ft_isdigit(int c);
bool	ft_isspace(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
