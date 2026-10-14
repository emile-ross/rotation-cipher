#include "header.h"

#include <string.h>

void safe_mem_copy(char *dst, size_t *dst_size, char *src, size_t src_size)
{
	if (*dst_size == src_size)
	{
		strncpy(dst, src, *dst_size);
		return;
	}

	/* reallocate memory corresponding to the size
	 * of the src string 
	 * we reallocate even if dst is larger than src
	 * because otherwise this will be wasted memory */
	*(dst_size) = strlen(src) + 1;
	dst = srealloc(dst, *dst_size);
	strncpy(dst, src, src_size);
}
