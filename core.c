#include "main.h"

int main(int ac, char **av, char **env)
{
	char rd[RD_BUF];
	int r , fd = STDIN_FILENO;
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
			make_args();
			fork();
			exec();
			*/
		}

	} while (interactive);

	return (0);
}
