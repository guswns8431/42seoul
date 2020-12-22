/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:21:48 by hyson             #+#    #+#             */
/*   Updated: 2020/12/22 17:41:37 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

void	*ft_memset(void *dest, int value, size_t size);
void	ft_bzero(void *dest, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);

#endif
