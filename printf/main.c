#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int d = 198;
	int make, real;

	make = ft_printf("-->|%4.4d|<--\n", d);
	printf("\n");
	real = printf("-->|%4.4d|<--\n", d);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
