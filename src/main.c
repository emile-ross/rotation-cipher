#include "header.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARS 3

int main(int argc, const char *argv[])
{
	uint16_t i = 0;
	char *str = NULL;
	char *file_content = NULL;
	uint16_t unused_arg_count = 0;
	size_t temp_length = 0;
	uint16_t temp_index = 0;

	argument_type *args = smalloc(sizeof(argument_type) * (unsigned)argc);
	args[0] = file_executed;

	if (argc <= 1)
	{
		fprintf(stderr, "Insufficient arguments | Arguments insuffisants\n");
		return 1;
	}

	for (i = 1; i < argc; i++)
	{
		if (cmp(argv[i], "-f", "--file"))
		{
			args[i] = used_flag;
			if (i + 1 < argc)
			{
				file_content = get_file_content(argv[i + 1]);
				if (file_content == NULL)
				{
					fprintf(stderr, "get_file_content() returned NULL\n");
					return 1;
				}
				printf("%s\n", file_content);
				return 0;
			}
			else
			{
				fprintf(stderr, "missing arguments for file reading\n");
			}
		}
		else
		{
			args[i] = unused_argument;
			unused_arg_count++;
		}
	}

	if (unused_arg_count == 1)
	{
		temp_index = argtype_to_index(argc, args, unused_argument);
		temp_length = strlen(argv[temp_index]) + 1;
		str = smalloc(temp_length);
		strncpy(str, argv[temp_index], temp_length);
		str[temp_length -1] = '\0';
	}

	menu(str, strlen(str));

	free(args);
	free(str);

	return 0;
}
