#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - start of the program
 * @argc: returns the number of command line
 * arguments passed by the user including the
 * name of the program
 * @argv: stores the entire list of command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	printf("argc: %d\n", argc);

	//char *argv[] = {"./arg", "I", "prefer", "coding", "in", "linux"};

	for (int i = 0; argv[i]; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	return (0);
}
