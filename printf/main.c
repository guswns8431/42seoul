#include "printf.h"

int main(void)
{
	int a = 1;

	ft_printf("%p", &a);
	printf("\n");
	printf("%p", &a);
	return (0);
}
