/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:57:57 by hyson             #+#    #+#             */
/*   Updated: 2021/11/23 19:56:01 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>

# define	SUCCESS	1
# define	FAIL	0
# define	ERROR	-1
# define	READ	0
# define	WRITE	1

typedef	int		t_bool;

typedef	enum	e_exit
{
	VALID,
	INVALID
}				t_exit;

typedef	struct	s_argvlist
{
	char *file1;
	char *file2;
	char *cmd1;
	char *cmd2;
	char *cmd1_path;
	char *cmd2_path;
	char *envp;
}				t_argvlist;

/*
** -----------------------------------------------------------------------------
**							F T _ F U N C T I O N S
** -----------------------------------------------------------------------------
*/

bool			ft_atoi(char **s, int *v);
bool			ft_calloc(void **tmp, size_t cnt, size_t size);
void			ft_free(void **ptr);
bool			ft_isdigit(int c);
bool			ft_isspace(int c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(const char *s, int fd);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
char			**ft_split(char const *s, char c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);

/*
**------------------------------------------------------------------------------
**							C O N T E X T
**------------------------------------------------------------------------------
*/

void			exit_invalid();
void			exit_valid();
void			parser(char **argv, t_argvlist *args, char **envp);
bool			redirection_stdin(char *path);
bool			redirection_stdout(char *path);
t_bool			exec(t_argvlist *arg, int *fd, char **envp, pid_t *pid);

#endif
