#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * splitString -splits the string into words
 * @str: the input string to split
 * @delimeer: used to split the string
 * @count: pointer to an integer variable that stores
 * the number of words in the string
 * Return: words
 */
char** splitString(const char* str, const char* delimiter, int* count)
{
	*count = 0;
	char* stringTo_split = strdup(str);
	char* token = strtok(stringTo_split, delimiter);
	while (token != NULL)
	{
		(*count)++;
		token = strtok(NULL, delimiter);
	}
	free(stringTo_split);
//allocation of memory for the array of words
	char** words = (char**)malloc(*count * sizeof(char*));
	if (words == NULL)
	{
		perror("Memory aloocation failed");
		exit(EXIT_FAILURE);
	}

	//splits the string into words
	int index = 0;
	char* stringTo_split1 = strdup(str);
	token = strtok(stringTo_split1, delimiter);
	while (token != NULL)
	{
		words[index] = strdup(token);
		index++;
		token = strtok(NULL, delimiter);
	}
	free(stringTo_split1);

	return (words);
}

/**
 * main - tests the splitString function
 * Return: zero
 */
int main(void)
{
	const char* inputString = "function that uses strtok() to split a string into words";
	const char* delimiter = " ";

	int count;
	char** words = splitString(inputString, delimiter, &count);

	printf("Input string: %s\n", inputString);
	printf("Words:\n");
	for (int n = 0; n < count; n++)
	{
		printf("%s\n", words[n]);
		free(words[n]);
	}

	free(words);

	return (0);
}
