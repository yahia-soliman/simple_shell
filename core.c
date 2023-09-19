#include "main.h"

void set_mode(int ac, char **av, int *mode, int *fd);
void w_err(char *sh, char *ch);
/**
 * main - goal of the program is to make a simple shell
 * @ac: number of words written  when calling the shell
 * @av: array of the given words when calling the shell
 * @env: array of environment variables
 *
 * Return: exit code (success) or (eles)
 */
int main(int ac, char **av, char **env)
{
	char *path, rd[RD_BUF], *ch_av[AV_BUF];
	int r, fd = STDIN_FILENO;
	int ch_id, ch_stat, in_mode = 1;

	set_mode(ac, av, &in_mode, &fd);
	do {
		if (in_mode)
			r = write(STDOUT_FILENO, "% ", 2);

		memset0(ch_av, sizeof(char *) * AV_BUF);
		r = RD_BUF;
		while (r != EOF && r == RD_BUF && (rd[RD_BUF - 1] != '\n'))
		{
			memset0(rd, sizeof(char) * RD_BUF);
			r = read(fd, rd, RD_BUF);
			if (r < 0)
				perror(av[0]);

			strtoav(rd, ch_av);
			if (*ch_av)
			{
				path = find_path(ch_av[0], env);
			if (path != NULL)
			{
				ch_id = fork();
				if (ch_id < 0)
					perror(av[0]);
				else if (ch_id == 0)
					execve(path, ch_av, env);
				else
				{
					wait(&ch_stat);
					if (path != *ch_av)
						free(path);
				}
			}
			else
				w_err(*av, *ch_av);
			free_av(ch_av);
			}
		}
	} while (in_mode);

	if (fd > 2)
		r = close(fd);
	return (0);
}

/**
 * set_mode - finds if the session is non interactive
 * @ac: ac from main func
 * @av: av from main func
 * @mode: adress of the mode to modify it if needed
 * @fd:   adress of the fd   to modify it if needed
 */
void set_mode(int ac, char **av, int *mode, int *fd)
{
	if (isatty(*fd) != 1 || ac > 1)
		*mode = 0;
	if (ac > 1)
		*fd = open(av[1], O_RDONLY);
	if (*fd < 0)
		perror(av[0]);
}

/**
 * w_err - command not found
 * @sh: name of the shell
 * @ch: name of the child
 */
void w_err(char *sh, char *ch)
{
	int r;

	r = write(STDOUT_FILENO, sh, str_len(sh));
	if (r > 0)
		r = write(STDOUT_FILENO, ": ", 2);
	if (r > 0)
		r = write(STDOUT_FILENO, ch, str_len(ch));
	if (r > 0)
		r = write(STDOUT_FILENO, ": command not found\n", 20);
	else
		perror(sh);
}
