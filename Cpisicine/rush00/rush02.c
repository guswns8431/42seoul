/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjki <hyeonjki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:35:52 by hyeonjki          #+#    #+#             */
/*   Updated: 2020/11/21 17:05:08 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_line(int x, char s, char m, char e)
{
	int c;

	c = 1;
	while (c <= x)
	{
		if (c == 1)
		{
			ft_putchar(s);
		}
		else if (1 < c && c < x)
		{
			ft_putchar(m);
		}
		else
			ft_putchar(e);
		c++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int l;

	l = 1;
	if (x < 0 || y < 0)
	{
		return ;
	}
	while (l <= y)
	{
		if (l == 1)
		{
			write_line(x, 'A', 'B', 'A');
		}
		else if (1 < l && l < y)
		{
			write_line(x, 'B', ' ', 'B');
		}
		else
			write_line(x, 'C', 'B', 'C');
		l++;
	}
}
