#include "header.h"

#include <string.h>

void safe_mem_copy(char *dst, size_t dst_size, char *src, size_t src_size)
{
	if (dst_size < src_size)
	{
		dst = srealloc(dst, src_size);
		strncpy(dst, src, src_size);
	}
	else if (dst_size > src_size)
	{
		dst = srealloc(dst, src_size);
		strncpy(dst, src, src_size);
	}
	else
	{
		strncpy(dst, src, dst_size);
	}
}
