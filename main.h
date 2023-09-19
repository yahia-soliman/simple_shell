#ifndef SIMPLE_SHELL_HEAD
#define SIMPLE_SHELL_HEAD


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


#define RD_BUF 1024
#define AV_BUF 1024


void *memset0(void *ptr, size_t size);
void strtoav(char *str, char **av, unsigned int size);
char *find_path(char *av0);


#endif /* SIMPLE_SHELL_HEAD */
