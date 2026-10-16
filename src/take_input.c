#include "header.h"

#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUFFER_SIZE (32)

int32_t getinput(input_types *action)
{
	char *input_buf = smalloc(DEFAULT_BUFFER_SIZE);
	long temp = 0;

	char *endptr = NULL;
	if (fgets(input_buf, DEFAULT_BUFFER_SIZE, stdin) == NULL)
	{
		(*action) = MENU_INVALID;
		free(input_buf);
		return -1;
	}

	if (strlen(input_buf) <= 1)
	{
		(*action) = MENU_EMPTY;
		return -1;
	}
	printf("INPUT: %s\n", input_buf);

	temp = strtol(input_buf, &endptr, 10);
	if (!(scmp(endptr, "\n")))
	{
		/* handle letters that could be entered */
		*(success) = False;
		free(input_buf);
		return -1;
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
