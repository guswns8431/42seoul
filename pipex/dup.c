#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	int tmp, ret;
	int tmp1, ret1;
	char buffer[4096];
	char buffer1[4096];

	tmp = open("test.txt", O_RDONLY);
	tmp1 = open("test1.txt", O_RDONLY);
	printf("%d %d\n", tmp, tmp1);
	if (tmp == -1 || tmp1 == -1)
	{
		printf("Error\n");
		return (1);
	}
	ret = dup2(tmp, STDIN_FILENO);
	ret1 = dup2(tmp, tmp1);
	printf("%d %d\n",  ret, ret1);
	if (ret == -1 || ret1 == -1)
	{
		printf("Error\n");
		return (0);
	}
	ret = read(STDIN_FILENO, buffer, 4096);
	buffer[ret] = '\0';
	printf("Result:\t%s\n", buffer);
	close(tmp);
	tmp = open("test.txt", O_RDONLY);
	ret1 = dup2(tmp, tmp1);
	ret1 = read(tmp1, buffer1, 4096);
	buffer1[ret1] = '\0';
	printf("Result:\t%s\n", buffer1);
	printf("ret : %d ret1 : %d\n", ret, ret1);
	return (0);
}
