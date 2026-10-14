#include "header.h"

#define DEFAULT_BUFFER_SIZE (32)

int32_t getint(Bool *success)
{
	char *input_buf = smalloc(DEFAULT_BUFFER_SIZE);
	long temp = 0;

	char *endptr = NULL;
	if (fgets(input_buf, DEFAULT_BUFFER_SIZE, stdin) == NULL)
	{
		*(success) = False;
		return 1;
	}

	temp = strtol(input_buf, &endptr, 10);
	if (temp < INT32MAX && temp > INT32MIN)
	{
		return (int32_t)temp;
	}
	*(success) = False;
	return 1;
}
