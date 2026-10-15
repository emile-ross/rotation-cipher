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
	printf("INPUT: %s\n", input_buf);

	temp = strtol(input_buf, &endptr, 10);
	if (!(scmp(endptr, "\n")))
	{
		*(success) = False;
		free(input_buf);
		return 1;
	}

	printf("INPUT: %ld\n", temp);
	if (temp < INT32MAX && temp > INT32MIN)
	{
		*(success) = True;
		free(input_buf);
		return (int32_t)temp;
	}

	*(success) = False;

	return 1;
}
