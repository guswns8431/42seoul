#include <stdio.h>
#include <unistd.h>

int main(void)
{
	execlp("ls", "ls", "-al", "fork.c", NULL);
	return (0);
}
