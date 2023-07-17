#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints all arguments without using ac
 * @av: null terminated array of strings
 * @ac: the number of items in av
 * Return: always 0
 */
int main(int ac, char **av)
{
	int m = 0;

	while (av[m])
	{
		printf("%s ", av[m]);
		m++;
	}
	printf("\n");
	return (0);
}
