/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:37:48 by hyson             #+#    #+#             */
/*   Updated: 2020/11/26 17:26:48 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_pre_str_is_char(int *flag, char *str, int i)
{
	if (ft_is_alpha(str[i - 1]) || ft_is_num(str[i - 1]))
	{
		*flag = 0;
	}
	else
	{
		*flag = 1;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			flag = 1;
		ft_pre_str_is_char(&flag, str, i);
		if (flag == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
