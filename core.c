#include "main.h"

void set_mode(int ac, char **av, int *mode, int *fd);
void w_err(char *sh, char *ch, int n_cmd);
int wr_int(int n);

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
	char not_last = 1, *path, rd[RD_BUF] = {0}, *ch_av[AV_BUF] = {0};
	int r = 0, fd = STDIN_FILENO, ch_id, ch_stat, in_mode = 1, n_cmd = 1;

	set_mode(ac, av, &in_mode, &fd);
	do {
		if (in_mode)
			r = write(STDOUT_FILENO, "#cisfun$ ", 9);

		memset0(ch_av, sizeof(char *) * AV_BUF);
		r = RD_BUF;
		while (r != EOF && r == RD_BUF)
		{
			memset0(rd, sizeof(char) * RD_BUF);
			r = read(fd, rd, RD_BUF);
			if (r < 0)
				perror(av[0]);
		do {
			not_last = strtoav(rd, ch_av);
			if (*ch_av)
			{
				if (built_in(ch_av, env))
					continue;
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
				w_err(*av, *ch_av, n_cmd);
			free_av(ch_av);
			}
		} while (not_last && r != EOF);
		}
	} while (in_mode && n_cmd++);

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
 * @n_cmd: command number
 */
void w_err(char *sh, char *ch, int n_cmd)
{
	int r;

	r = write(STDOUT_FILENO, sh, str_len(sh));
	if (r > 0)
		r = write(STDOUT_FILENO, ": ", 2);
	if (r > 0)
		r = wr_int(n_cmd);
	if (r > 0)
		r = write(STDOUT_FILENO, ": ", 2);
	if (r > 0)
		r = write(STDOUT_FILENO, ch, str_len(ch));
	if (r > 0)
		r = write(STDOUT_FILENO, ": not found\n", 13);
	else
		perror(sh);
}

/**
 * wr_int -  write  integer to stdout
 * @n:       number to print
 *
 * Return:   number of printed digits
 */
int wr_int(int n)
{
	unsigned int d = n, i = 1;
	int r = 0;
	char c;

	while (d != d % (i * 10))
	{
		i *= 10;
		if ((i * 10) % 10 != 0)
			break;
	}

	while (i >= 1)
	{
		c = d / i + '0';
		r += write(STDOUT_FILENO, &c, 1);
		d %= i;
		i /= 10;
	}
	return (r);
}
