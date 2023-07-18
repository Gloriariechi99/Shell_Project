#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - uses strtok to print string of words in new lines
 * Return: words, null
 */
int main(void)
{
        char *src = "Gloria Moraa Riechi";
        char *str = malloc(sizeof(char) *strlen(src));
        char *delim = " ";
        char *token;

        strcpy(str, src);

        token = strtok(str, delim);
        while (token)
        {
                printf("%s\n", token);
                token = strtok(NULL, delim);
        }

        return (0);
}
