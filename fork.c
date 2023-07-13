#include <stdio.h>
#include <unistd.h>
/**
 * main - prototype
 * Return: 0 for success -1 for fail
 */
int main(void)
{
	pid_t pid;

	printf("Before fork\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	printf("After fork\n");
	return (0);
}
