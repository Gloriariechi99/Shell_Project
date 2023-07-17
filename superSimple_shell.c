#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - pprogram to execute commands with
 * their full path without any arguments
 * Return: zero
 */
int main()
{
	char cmd[50];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		//removes trailling newline character from command
		size_t length = strlen(cmd);
		if (length > 0 && cmd[length - 1] == '\n')
		{
			cmd[length - 1] = '\n';
		}

		//child process
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork has failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execl(cmd, cmd, NULL);
			perror("Exec has failed");
			exit("Exec has failed");
		}
		//parent process

		else
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("The child process exited with status: %d\n", WEXITSTATUS(status));
			}
			else if(WIFSIGNALED(status))
			{
				printf("The child process terminated by signal: %d\n", WTERMSIG(status));
			}
		}
	}
	return (0);
}
