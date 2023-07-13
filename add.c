#include <stdio.h>
#include <unistd.h>
/**
 * main - add numbers and show pid
 * Return: Always zero
 */
int main(void)
{
	int decks;
	pid_t pid;
	pid_t ppid;
	
	pid = getpid();
	ppid = getppid();

	puts("Enter a number of decks");
	scanf("%i", &decks);
	if (decks < 1){
		puts("This is not a valid number of decks");
		return (1);
	}
	printf("There are %i cards\n", decks * 52);
	printf("The pid is %u\n", pid);
	printf("The ppid is %u\n", ppid);

	return (0);
}
