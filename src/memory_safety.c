#include <stdlib.h>
#include <stdio.h>

/* allocate memory but adds NULL error checking */
void *smalloc(size_t size)
{
	void *ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr, "The kernel failed to allocate memory of size %lu\n", size);
		exit(EXIT_FAILURE);
	}
	return ptr;
}
