#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	int make, real;

	make = ft_printf("%.3s", b);
	printf("\n");
	real = printf("%.3s", b);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
