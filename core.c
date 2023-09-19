#include "main.h"

/**
 * main - goal of the program is to make a simple shell
 * @ac: number of words written  when calling the shell
 * @av: array of the given words when calling the shell
 * @env: array of environment variables
 *
 * Return: exit code (success) or (eles)
 */
/*int main(int ac, char **av, char **env)*/
int main(int ac, char **av)
{
	char rd[RD_BUF];
	int r, fd = STDIN_FILENO;
	int interactive = 1;

	if (isatty(fd) != 1 || ac > 1)
		interactive = 0;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror(av[0]);

	do {
		if (interactive)
			r = write(STDOUT_FILENO, "% ", 2);

		r = RD_BUF;
		while (r != EOF && r == RD_BUF && (rd[RD_BUF - 1] != '\n'))
		{
			r = read(fd, rd, RD_BUF);
			if (r < 0)
				perror(av[0]);

			/*
			strtoav(rd, ch_av, AV_BUF);
			path = find_path(ch_av[0]);
			if (path != NULL)
				ch_id = fork();
				if (ch_id < 0)
					perror();
				else if (ch_id == 0)
					execve(path, ch_av, env);
				else
					wait(&ch_stat);
			*/
		}

	} while (interactive);

	return (0);

