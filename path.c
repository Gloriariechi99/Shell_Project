#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	const char* path = getenv("PATH");

	if (path == NULL)
	{
		printf("The path variable is note set\n");
		return (1);
	}

	printf("Searching for files in the current path\n");

	char* pathCopy = strdup(path);
	char* token = strtok(pathCopy, ":");

	while (token != NULL)
	{
		printf("Directory: %s\n", token);

		token = strtok(NULL, ":");
	}
	
	free(pathCopy);

	return (0);
}
