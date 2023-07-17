#include <stdio.h>
#include <unistd.h>
/**
 * main - prototype
 * Return: 0 for success -1 for fail
 */
int main(void)
{
	pid_t pid;
	pid_t ppid;

	printf("Before fork\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(35);
		printf("child\n");
	}
	else
	{
		ppid = getpid();
		printf("Parent pid is: %u\n", ppid);
	}

	return (0);
}
