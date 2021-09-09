#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int ret;
	char *cmd[] = { "ls", "-l", (char *)0 };
	char *env[] = { "HOME=/usr/home", "LOGNAME=a", (char *)0 };

	ret = execve ("/bin/ls", cmd, env);
	printf("%d", ret);
	return (0);
}
