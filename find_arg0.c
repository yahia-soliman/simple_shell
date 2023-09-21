#include "util.h"
#include <unistd.h>
#include <stdio.h>

int is_path(char *s);
/**
 * find_path - finds the path to execute a program
 * @av0: the name of the program to find its  path
 * @env: the array of environment  variables
 *
 * Return: the full path or NULL if not found
 */
char *find_path(char *av0, char **env)
{
	char was, *path, *add_sl, *prog;
	int i = 0, len;

	if (is_path(av0) && access(av0, X_OK) == 0)
		return (av0);

	path = get_env("PATH", env);
	if (path == NULL)
		return (NULL);

	path += 5;
	len = str_len(path);
	len += (len > 0);

	while (len--)
	{
		if (path[i] == ':' || path[i] == '\0')
		{
			was = path[i];
			path[i] = '\0';
			if (path[i - 1] != '/')
			{
				add_sl = str_concat(path, "/");
				prog = str_concat(add_sl, av0);
				free(add_sl);
			}
			else
				prog = str_concat(path, av0);

			path[i] = was;
			if (access(prog, X_OK) != 0)
			{
				free(prog);
				if (was)
				{
				path += i + 1;
				i = 0;
				}
			}
			else
				return (prog);
		}
		else
			i++;
	}

	return (NULL);
}

/**
 * is_path - checks if a given string represents a path
 * @s: string to check
 * Return: 1 if path and 0 if not
 */
int is_path(char *s)
{
	return (s[0] == '/' ||
		str_diff(s, "./") == 0 ||
		str_diff(s, "../") == 0);
}
