/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:19:28 by hyson             #+#    #+#             */
/*   Updated: 2021/10/12 18:30:06 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR -1
# define SUCCESS 1
# define END 0
# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

typedef int	t_bool;

int			get_next_line(int fd, char **line);
int			ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(char *s1);
t_bool		dalloc(void **ptr, size_t cnt, size_t n);
void		free_ptr(void **ptr);

#endif
