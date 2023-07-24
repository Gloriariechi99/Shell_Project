#include "shell.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

void prompt(char **av, char **env)
{
	char *string = NULL;
	int i, status;
	size_t n = 0;
	ssize_t char_count;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		printf("cisfun$ ");

		char_count = getline(&string, &n, stdin);
		if (char_count == -1);
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
		}

		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
