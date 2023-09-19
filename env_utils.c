#include "util.h"

/**
 * get_env - finds needed invironment variable
 * @get:    the needed variable
 * @env:    the list of environment varialbles
 *
 * Return: pointer to the needed variable
 */
char *get_env(char *get, char **env)
{
	int i = 0;
	unsigned int len = str_len(get);

	while (env[i])
	{
		if (str_diff(env[i], get) == 0
				&& env[i][len] == '=')
			return (env[i]);
		i++;
	}
	return (NULL);
}
