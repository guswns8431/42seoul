#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	int make, real;

	make = ft_printf("a");
	printf("\n");
	real = printf("%5%");
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
