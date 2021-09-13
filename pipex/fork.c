#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I got a pid %d internally\n", pid);
		printf("Child: Exiting with Code 0\n");
	}
	else if (pid)
	{
		printf("Parent: I have a Child which pid is %d\n", pid);
		wait(NULL);
		printf("Parent: Exiting with Code 0\n");
	}
	return (0);
}
