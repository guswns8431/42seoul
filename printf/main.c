#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int d = -1;
	int x = -1;
	int make, real;

	make = ft_printf("-->|%.p|<--\n", a);
	printf("\n");
	real = printf("-->|%.p|<--\n", a);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
