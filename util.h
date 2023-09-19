#ifndef UTILITIES_HEADER
#define UTILITIES_HEADER

#include <stdlib.h>

/* string */
unsigned int str_len(char *str);
char *str_concat(char *s1, char *s2);
int str_diff(char *s1, char *s2);

/* memory */
void *memset0(void *ptr, unsigned int n);

/* environment */
char *get_env(char *get, char **env);

#endif /* UTILITIES */
