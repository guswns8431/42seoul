/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:45:48 by hyson             #+#    #+#             */
/*   Updated: 2021/05/10 23:08:54 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // 이건 빼야해
# include <fcntl.h> // 이것도 빼야해

# define ERROR -1
# define HAS_BEEN_READ 1
# define EOF_REACHED 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

int	get_next_line(int fd,char **line);
char *ft_backup(char *s1, char *s2);
int	ft_check_newline(char *str);
int		ft_split_line(char **save, char **line, int idx);
int		ft_exception(char **save, char **line, int read_size);
int	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(char *s1);

#endif
