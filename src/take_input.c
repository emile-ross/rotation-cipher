#include "header.h"

#include <stdlib.h>

#define DEFAULT_BUFFER_SIZE (32)

int32_t getint(Bool *success)
{
	char *input_buf = smalloc(DEFAULT_BUFFER_SIZE);
	long temp = 0;

	char *endptr = NULL;
	if (fgets(input_buf, DEFAULT_BUFFER_SIZE, stdin) == NULL)
	{
		*(success) = False;
		free(input_buf);
		return 1;
	}

	temp = strtol(input_buf, &endptr, 10);
	if (!(*endptr == '\0'))
	{
		*(success) = False;
		return 1;
	}

	if (temp < INT32MAX && temp > INT32MIN)
	{
		*(success) = True;
		return (int32_t)temp;
	}

	*(success) = False;

	return 1;
}
