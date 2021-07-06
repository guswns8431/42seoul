/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:12:28 by hyson             #+#    #+#             */
/*   Updated: 2021/07/05 18:00:21 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isinteger(char *s, t_stack **a)
{
	int			i;
	long long	num;
	int		sign = 1;

	i = -1;
	num = 0;
	while (s[++i])
	{
		if (s[i] == '-')
		{
			sign = -1;
			++i;
		}
		num = num * 10 + (s[i] - '0');
	}
	num *= sign;
	insert_node(a, num);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

int		ft_isnum(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '-')
			continue ;
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

bool	ft_check_error(int argc, char **argv, t_stack **a)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (!ft_isnum(argv[i]) || !ft_isinteger(argv[i], a))
			return (true);
		j = i;
		while (++j < argc)
			if (ft_strcmp(argv[i], argv[j]))
				return (true);
	}
	return (false);
}

int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	create_stack(&a);
	create_stack(&b);
	if(ft_check_error(argc, argv, &a))
		write(2, "Error\n", 6);
	push(&a, &b, 'b');
	push(&a, &b, 'b');
	write(1, "test\n", 5);

	t_node *cur = a->top;
	while (cur->prev != NULL)
	{
		printf("%d", cur->val);
		cur = cur->prev;
		if (cur->prev == NULL)
			printf("%d", cur->val);
	}
	printf("\n");
	cur = b->top;
	while (cur->prev != NULL)
	{
		printf("%d", cur->val);
		cur = cur->prev;
		if (cur->prev == NULL)
			printf("%d", cur->val);
	}
	return (0);
}
