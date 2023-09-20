#include "main.h"

/**
 * print_env - prints environment variables
 * @env: given environment
 */
void print_env(char **env)
{
	int len, i = 0;

	while (env[i] != NULL)
	{
		len = str_len(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * exit_sh - exits the shell
 * @av: user input
 * @ch_stat: return of last fork
 */
void exit_sh(char **av, int ch_stat)
{
		free_av(av);
		exit(ch_stat);
}

/**
 * built_in - exits the shell
 * @av:	 user inputs
 * @env: environment variables
 * @ch_stat: return of last fork
 *
 * Return: True(1) False(0)
 */
int built_in(char **av, char **env, int ch_stat)
{
	int i = 0;
	char *in[] = {"exit", "env", NULL};

	while (in[i] != NULL)
	{
		if (str_diff(in[i], av[0]) == 0 &&
			str_len(in[i]) == str_len(av[0]))
			break;
		i++;
	}

	if (i == 0)
		exit_sh(av, ch_stat);
	else if (i == 1)
		print_env(env);
	else
		return (0);
	return (1);
}
