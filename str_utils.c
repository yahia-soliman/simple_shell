#include "util.h"
/**
 * str_len - counts chars in a string
 * @str: string to count from
 *
 * Return: number of characters count
 */
unsigned int str_len(char *str)
{
	if (*str)
		return (1 + str_len(str + 1));
	return (0);
}

/**
 * str_concat - canatenates two strings
 * @s1: first  string
 * @s2: second string
 *
 * Return: pointer to concated result
 */
char *str_concat(char *s1, char *s2)
{
	int len1, len2, i;
	char *r, s0[] = {0};

	len1 = len2 = i = 0;

	if (s1 == NULL)
		s1 = s0;
	else
		len1 = str_len(s1);

	if (s2 == NULL)
		s2 = s0;
	else
		len2 = str_len(s2);
	len2 += len1;


	r = malloc(sizeof(char) * len2 + 1);
	while (r != NULL && i < len1)
	{
		*(r + i) = s1[i];
		i++;
	}
	while (r != NULL && i <= len2)
	{
		*(r + i) = s2[i - len1];
		i++;
	}

	return (r);
}

/**
 * str_diff - compares two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: if both are identical
 *         or s1 contains s2
 *         then return 0
 *         else return difference
 */
int str_diff(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] - s2[i] == 0 && s2[i] != 0)
		i++;

	if (s2[i] == 0)
		return (0);
	return (s1[i] - s2[i]);
}
