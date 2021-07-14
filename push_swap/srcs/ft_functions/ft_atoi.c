#include "push_swap.h"

static bool	overflowed(int former, int latter)
{
	if (((former >= 0) != ((former << 1) >= 0))
		|| ((former >= 0) != ((former << 2) >= 0))
		|| ((former >= 0) != ((former << 3) >= 0))
		|| ((former >= 0) != (latter >= 0)))
		return (true);
	return (false);
}

bool	ft_atoi(char **s, int *v)
{
	int	sign;
	int	tmp;

	while (jisspace(**s))
		++(*s);
	sign = 1;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	if (!jisdigit(**s))
		return (false);
	*v = (*((*s)++) - '0') * sign;
	while (jisdigit(**s))
	{
		tmp = (*((*s)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *v * 10 + tmp;
		if (overflowed(*v, tmp))
			return (false);
		*v = tmp;
	}
	return (true);
}
