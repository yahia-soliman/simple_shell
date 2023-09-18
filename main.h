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


#endif /* SIMPLE_SHELL_HEAD */
