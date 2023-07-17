#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - strat of the program
 * Return: 0
 */
int main()
{
	int children = 5;
	int n;

	for (n = 0; n < children; n++)
	{
		pid_t pid= fork();

		if (pid < 0)
		{
			perror("Fork has failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Child process %d is executing ls -l /tmp/n", n + 1);
			execl("/bin/ls", "ls", "-l", "/tmp", (char *)NULL);
			perror("Exec has failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			wait(&status);

			if (WIFEXITED(status))
			{
				printf("The child process %d exited with status %d\n", n + 1, WEXITSTATUS(status));
			}
			else
			{
				printf("The child process %d exited abnormally\n", n + 1);
			}
		}
	}
	return (0);
}
