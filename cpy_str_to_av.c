#include "main.h"
/**
 * strtoav - copy words from string into argument vector
 * @str: the source to copy from
 * @av:  the array of string to copy each word into
 *
 * Return: not yet decided
 */
void strtoav(char *str, char **av)
{
	int n = 0, i = 0, w, j;

	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == ' ')
			i++;
		else
		{
			w = i;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
				i++;
			av[n] = malloc((1 + i - w) * sizeof(char));

			j = 0;
			while (w < i)
			{
				av[n][j] = str[w];
				w++;
				j++;
			}
			av[n][j] = '\0';
			n++;
		}
	}
	av[n] = NULL;
}

/**
 * free_av - frees memory allocated by strtoav
 * @av: same argument vector  used  in strtoav
 */
void free_av(char **av)
{
	while (*av)
	{
		free(*av);
		av++;
	}
}
