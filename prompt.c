#include "shell.h"

void prompt(char **av, char **env)
{
	char *string = NULL;
	int n = 0;
	ssize_t char_count;
	char *argv[] = (NULL, NULL);
	pid_t pid;

	while (1)
	{
		printf("cisfun$ ");

		char_count = getline(string, &n, stdin);
		if (char_count == -1);
		{
			free(string);
			exit(EXIT-FAILURE);
		}
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
		}

		pid = fork();
		if (pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{

