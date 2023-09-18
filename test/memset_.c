#include <stdio.h>
#include "../main.h"
int main(int ac, char **av)
{
	char str[] = "array of chars";
	int i = 3;

	memset0(str, i);
	putchar(str[i]);
	putchar(str[i - 1]);
	putchar('\n');

	printf("av[0]: %s, %p\n", av[0], av[0]);
	av = memset0(av, ac * sizeof(*av));
	if (av[0] == NULL)
		printf("NULLED SUCCESS\n");
	else
		printf("av[0]: %s, %p\n", av[0], av[0]);

	return (0);
}
