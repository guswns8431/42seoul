/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:45:48 by hyson             #+#    #+#             */
/*   Updated: 2021/05/14 16:13:28 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# define ERROR          -1
# define SUCCESS        1
# define END            0
# define TRUE           1
# define FALSE          0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   42
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
