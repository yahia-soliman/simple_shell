/**
 * memset0 - sets memory to 0 in each byte
 * @ptr: the address of the first byte
 * @n: number of bytes to set to 0
 * Return: same as @ptr
 */
void *memset0(void *ptr, unsigned int n)
{
	char *cptr = (char *)ptr;

	while (n--)
		*(cptr + n) = 0;

	return ((void *)ptr);
}
