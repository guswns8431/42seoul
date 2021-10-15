/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:15:26 by hyson             #+#    #+#             */
/*   Updated: 2021/10/14 20:35:02 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool		parse(char *line, int fd)
{
	char	*tmp;
	int		id;

	tmp = line;
	id = 0;

	/*
	** 구분자별로 모듈 나누기
	** 모듈별로 담아놓을 변수가 다름
	*/
	if (identifier(line) == ERROR)
		e_identifier((void **)&line, fd);
	return (SUCCESS);
}
