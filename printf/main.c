#include "printf.h"

int main(void)
{
	char* a = NULL;
	char* b = "test";
	char* s = "abc";
	int make, real;

	make = ft_printf("-->|%-16.*s|<--\n", -4, s);
	printf("\n");
	real = printf("-->|%-16.*s|<--\n", -4, s);
	printf("\n");
	printf("make : %d, real : %d\n",make, real);
	return (0);
}
