#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int d = -1;
	int x = -1;
	int make, real;

	make = ft_printf("-->|%0*%|<--\n", -3);
	printf("\n");
	real = printf("-->|%0*%|<--\n", -3);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
