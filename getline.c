#include <stdio.h>
/**
 * main - prints $ and waits for user to 
 * enter a command and prints it on the next line
 * Return: 0
 */

int main(void)
{
	printf("$ ");

	fflush(stdout);

	char count[45];
	fgets(count, sizeof(count), stdin);

	printf("%s", count);

	return (0);
}
