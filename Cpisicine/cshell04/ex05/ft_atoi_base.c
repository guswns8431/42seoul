/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:48:04 by hyson             #+#    #+#             */
/*   Updated: 2020/12/02 20:22:33 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *base)
{
	int strlen;

	strlen = 0;
	while (*base)
	{
		strlen++;
		base++;
	}
	return (strlen);
}

int	ft_is_in_string(char ch, char *str)
{
	while (*str)
	{
		if (ch == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_validation(char *base)
{
	char	*base_addr;
	int		i;
	int		j;

	base_addr = base;
	if (!*base || ft_strlen(base) == 1)
		return (0);
	while (*base_addr++)
		if (ft_is_in_string(*base_addr, "+- \n\t\r\v\f"))
			return (0);
	i = -1;
	while (i++ < ft_strlen(base) - 1)
	{
		j = i;
		while (j++ < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

int	ft_a_to_i(char ch, char *base)
{
	int i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == ch)
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int radix;
	int	tmp;

	result = 0;
	sign = 1;
	radix = ft_strlen(base);
	if (!ft_check_validation(base))
		return (0);
	while (ft_is_in_string(*str, " \n\t\r\v\f"))
		str++;
	while (ft_is_in_string(*str, "+-"))
		if (*str++ == '-')
			sign *= -1;
	while ((tmp = ft_a_to_i(*str, base)) != -1)
	{
		result *= radix;
		result += tmp;
		str++;
	}
	return (sign * result);
}
