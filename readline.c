#include <stdio.h>
#include <stdlib.h>

/**
 * char - used to define the function
 * Return: line
 */

char* moraa_getline()
{
	char* line = NULL;
	size_t length = 0;

	if (getline(&line, &length, stdin) == -1)
	{
		perror("getline error");
		exit(EXIT_FAILURE);
	}

	return line;
}

/**
 * main - consists of the getline function
 * Return: zero
 */

int main()
{
	printf("$ ");
	fflush(stdout);

	char* count = moraa_getline();

	printf("%s", count);

	free(count);

	return (0);
}
