#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	int make, real;

	make = ft_printf("-->|%*.c|<--\n", -4, 'c');
	printf("\n");
	real = printf("-->|%*.c|<--\n", -4, 'c');
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
