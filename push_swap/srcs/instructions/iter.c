#include "push_swap.h"

void	iter(t_mother **m, int cnt, void (*f)(t_mother **, char *), char *cmd)
{
	int		i;

	i = -1;
	while (++i < cnt)
		f(m, cmd);
}
