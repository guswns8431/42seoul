/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:27:56 by hyson             #+#    #+#             */
/*   Updated: 2020/12/01 18:27:42 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_in_string(char ch, char *str)
{
	while (*str)
	{
		if (ch == *str)
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	ft_is_whitespace(char ch)
{
	if (ft_is_in_string(ch, " \n\t\v\r\f"))
		return (1);
	return (0);
}

int	ft_is_operator(char ch)
{
	if (ft_is_in_string(ch, "-+"))
		return (1);
	return (0);
}

int	ft_is_numeric(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	while (ft_is_operator(*str))
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (ft_is_numeric(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (sign * result);
}
