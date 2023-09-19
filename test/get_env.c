#include "../main.h"

/**
 * main - purpose is to test
 * @ac:  number of arguments
 * @av:  array  of arguments
 * @env: array of envrnments
 * Return: zero
 */
int main(int ac, char **av, char **env)
{
	char *wanted = "Usage: get_env <varialbe_name>";

	if (ac > 1)
		wanted = get_env(av[1], env);

	printf("(%s)\n", wanted);

	return (0);
}
