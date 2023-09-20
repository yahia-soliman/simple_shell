#include "main.h"

int is_end(int c);
/**
 * strtoav - copy words from string into argument vector
 * @str: the source to copy from
 * @av:  the array of string to copy each word into
 *
 * Return: the end of command (0 if the end of file)
 */
char strtoav(char *str, char **av)
{
	int comment = 0, n = 0, w, wi, c;
	static int i = 0;

	c = !(is_end(str[i]));
	while (c)
	{
		if (str[i] == '#')
			comment = 1;
		if (str[i] == ' ' || comment)
			i++;
		else
		{
			w = i;
			c = !(is_end(str[i]));
			while (str[i] != ' ' && c)
			{
				i++;
				c = !(is_end(str[i]));
			}
			av[n] = malloc((1 + i - w) * sizeof(char));

			wi = 0;
			while (w < i)
			{
				av[n][wi] = str[w];
				w++;
				wi++;
			} av[n][wi] = '\0';
			n++;
		}
		c = !(is_end(str[i]));
	}

	av[n] = NULL;

	c = (str[i] == '\0');
	if (c)
		i = 0;
	else
		i++;
	return (i);
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

/**
 * is_end - checks if a char is the end of command
 * @c: the character to check
 *
 * Retrun: 1 if c is end character
 */
int is_end(int c)
{
	/*
	char endc[3] = {'\n', ';', '\0'};
	char *ptr = endc;
	int i = 0;

	while (i <= 3)
	{
		if (c != *ptr)
		{
			ptr++;
			i++;
		}
		else
			break;
	}

	if (i <= 3)
		return (1);
	return (0);
	*/
	if (c == 0 || c == 10 || c == 59)
		return (1);
	else
		return (0);
}
