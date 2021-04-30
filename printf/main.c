#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int d = -1;
	int x = -1;
	int make, real;

	make = ft_printf("%-*.*d", -2, 2, -2147483648);
	printf("\n");
	real = printf("%-*.*d", -2, 2, -2147483648);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
