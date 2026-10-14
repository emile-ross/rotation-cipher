#include <stdlib.h>
#include <stdio.h>

/* allocate memory but adds NULL error checking */
void *smalloc(size_t size)
{
	void *ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
	{
		fprintf(stderr, "smalloc(): The kernel failed to allocate memory of size %lu\n", size);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

void *srealloc(void *old_ptr, size_t size)
{
	void *ptr = NULL;
	ptr = realloc(old_ptr, size);
	if (ptr == NULL)
	{
		fprintf(stderr, "srealloc(): The kernel failed to re-allocate memory of size %lu\n", size);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

void *scalloc(size_t n, size_t size)
{
	void *ptr = NULL;
	ptr = calloc(n, size);
	if (ptr == NULL)
	{
		fprintf(stderr, "smalloc(): The kernel failed to allocate memory of size %lu\n", size);
		exit(EXIT_FAILURE);
	}
	return ptr;
}
