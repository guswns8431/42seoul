/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:45:48 by hyson             #+#    #+#             */
/*   Updated: 2021/05/11 18:17:38 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h> // 이것도 빼야해
# include <stdio.h> // 이건 빼야해
# include <stdlib.h>
# include <unistd.h>

# define ERROR          -1
# define SUCCESS        1
# define END            0
# define TRUE           1
# define FALSE          0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX      4096
# endif

typedef int             t_bool;

int	            	    get_next_line(int fd, char **line);
int                     ft_strlen(char *s);
size_t                  ft_strlcpy(char *dst, const char *src, size_t dstsize);
char                    *ft_strdup(char *s1);
t_bool                  dalloc(void **ptr, size_t cnt, size_t n);
void                    free_ptr(void **ptr);

#endif
