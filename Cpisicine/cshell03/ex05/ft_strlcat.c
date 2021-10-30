/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:58:53 by hyson             #+#    #+#             */
/*   Updated: 2020/12/01 11:09:13 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*d_start;
	char			*s_start;
	unsigned int	p_length;
	unsigned int	s_length;

	d_start = dest;
	s_start = src;
	while (size && *dest)
	{
		++dest;
		--size;
	}
	while (*src)
		++src;
	p_length = (unsigned int)(dest - d_start);
	s_length = (unsigned int)(src - s_start);
	if (!size)
		return (p_length + s_length);
	while (*s_start && size-- > 1)
		*dest++ = *s_start++;
	*dest = '\0';
	return (p_length + s_length);
}
