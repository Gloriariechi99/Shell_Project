#include <stdio.h>
#include <stdlib.h>

char* own_getline()
{
	int count = 10;
	int length = 0;
	char* line = malloc(count * sizeof(char));

	if (line == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	int m;
	while ((m = getchar()) != '\n' && m != EOF)
	{
		line[length++] = (char) m;

		if (length >= count)
		{
			count *= 2;
			char* new_line = realloc(line, count * sizeof(char));
			if (new_line == NULL)
			{
				perror("|Memory allocation failed");
				free(line);
				exit(EXIT_FAILURE);
			}
			line = new_line;
		}
	}
	if (length == 0 && m == EOF)
	{
		free(line);
		return NULL;
	}
	line[length] = '\0';

	return line;
}
int main()
{
	printf("$ ");
	fflush(stdout);

	char* command = own_getline();

	if (command != NULL)
	{
		printf("%s\n", command);
	}

	return (0);
}
