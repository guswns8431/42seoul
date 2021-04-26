#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int d = -1;
	int make, real;

	make = ft_printf("-->|%-15.p|<--\n", a);
	printf("\n");
	real = printf("-->|%-15.p|<--\n", a);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
