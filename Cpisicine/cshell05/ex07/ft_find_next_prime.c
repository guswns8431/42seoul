/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:15:38 by hyson             #+#    #+#             */
/*   Updated: 2020/12/03 21:04:40 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= (long long)nb)
		i++;
	return (--i);
}

int	ft_is_prime(int nb)
{
	int i;
	int sqrt;

	i = 1;
	sqrt = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	while (++i <= sqrt)
	{
		if (!(nb % i))
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int next_prime;

	next_prime = nb;
	while (!ft_is_prime(next_prime))
		next_prime++;
	return (next_prime);
}
