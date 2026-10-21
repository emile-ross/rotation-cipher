#include "header.h"

#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUFFER_SIZE (32)
void block(void);

int32_t getinput(input_types *action)
{
	char *input_buf = smalloc(DEFAULT_BUFFER_SIZE);
	long temp = 0;
	size_t input_length = 0;

	char *endptr = NULL;
	printf("input | entree: ");
	if (fgets(input_buf, DEFAULT_BUFFER_SIZE, stdin) == NULL)
	{
		(*action) = MENU_INVALID;
		free(input_buf);
		return -1;
	}
	input_length = strlen(input_buf);

	if (input_length <= 1)
	{
		(*action) = MENU_EMPTY;
		free(input_buf);
		return -1;
	}

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
			case '0':
			case 'S':
			case 's':
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

			case 'Y':
			case 'y':
			case 'C':
			case 'c':
				fprintf(stderr, "Copying to clipboard is currently unsupported\n");
				fprintf(stderr, "There are some plans for supporting it in the future however\n");
				block();
				(*action) = MENU_COPY;
				break;

			default:
				(*action) = MENU_INVALID;
				break;
			}
		}
		free(input_buf);
		return -1;
	}

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
	/* blocks input until we get a \n */
	fgets(str, 2, stdin);
}
