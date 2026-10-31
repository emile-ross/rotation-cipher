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
	(*dst_size) = strlen(src) + 1;
	dst = srealloc(dst, *dst_size);
	strncpy(dst, src, src_size);
}

void strip_newline(char *string, size_t length)
{
	uint32_t i = 0;
	if (length <= 2)
	{
		return;
	}

	for (i = (uint32_t)length; i > 0; i--)
	{
		if (string[i] == '\n' || string[i] == '\r')
		{
			string[i] = '\0';
		}
		else if (string[i] == '\0')
		{
			continue;
		}
		else 
		{
			break;
		}
	}
}
