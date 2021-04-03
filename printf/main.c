#include "printf.h"

int main(void)
{
	// int a = 2;
	int make, real;

	make = ft_printf("%12.p", "123");
	printf("\n");
	real = printf("%12.p", "123");
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
