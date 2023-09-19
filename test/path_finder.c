#include "../main.h"

/**
 * main - purpose is to test
 * @ac:  number of arguments
 * @av:  array  of arguments
 * @env: array of environmnt
 *
 * Return: zero
 */
int main(int ac, char **av, char **env)
{
	char *path;
	int i = 0;

	if (ac > 1)
	{
	while (av[++i])
	{
		path = find_path(av[i], env);
		if (path)
		{
			printf("(%s)\n", path);
			free(path);
			printf("(%s)\n", av[i]);
		}
		else
			printf("%s not found\n", av[i]);
	}
	}
	else
		printf("Usage: %s <prog1_name> <prog2_name> ...\n", av[0]);

	return (0);
}
