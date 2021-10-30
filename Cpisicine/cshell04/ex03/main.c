#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	char *str = "  ---+--+2147483648ab567";
	printf("%d", ft_atoi(str));
	return (0);
}
