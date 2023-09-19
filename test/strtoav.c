#include "../main.h"

/**
 * main - purpose is to test
 * @i:   number of arguments
 * @av:  array  of arguments
 * Return: zero
 */
int main(int i, char **av)
{
	char *ch_av[AV_BUF];

	strtoav(av[1], ch_av);

	i = 0;
	while (ch_av[i])
	{
		printf("(%s)\n", ch_av[i]);
		i++;
	}

	free_av(ch_av);
	return (0);
}
