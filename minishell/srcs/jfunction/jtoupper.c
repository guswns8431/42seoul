/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtoupper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:06:31 by jseo              #+#    #+#             */
/*   Updated: 2021/12/26 22:55:22 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jfunction.h"

int	jtoupper(int c)
{
	if (jisalpha(c) == 2)
		return (c - 32);
	return (c);
}
