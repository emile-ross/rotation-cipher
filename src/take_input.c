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
		free(input_buf);
		return -1;
	}
	printf("INPUT: %s\n", input_buf);

	temp = strtol(input_buf, &endptr, 10);
	if (!(scmp(endptr, "\n")))
	{
		/* handle letters that could be entered */
		(*action) = MENU_INVALID;
		if (input_length >= 2)
		{
			switch (input_buf[0])
			{
			case 'Q':
			case 'q':
				(*action) = MENU_EXIT;
				break;
			case 'b':
			case 'u':
			case 'r':
				(*action) = MENU_UNDO;
				break;

			case ' ':
			case '\t':
				(*action) = MENU_EMPTY;
				break;
			case 'c':
				fprintf(stderr, "Copying is currently unsupported\n");
				block();

			}
		}
		free(input_buf);
		return -1;
	}

	printf("INPUT: %ld\n", temp);
	if (temp < INT32MAX && temp > INT32MIN)
	{
		(*action) = MENU_ENTRY;
		free(input_buf);
		return (int32_t)temp;
	}

	(*action) = MENU_INVALID;

	return 1;
}

void block(void)
{
	char str[2];
	printf("Press enter to continue\n");
	fgets(str, 2, stdin);
}
