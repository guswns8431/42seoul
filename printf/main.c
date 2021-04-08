#include "printf.h"

int main(void)
{
	// int a = 2;
	int make, real;

	make = ft_printf("aabc%ds", 12);
	printf("\n");
	real = printf("aabc%ds", 12);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
