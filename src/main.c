#include "header.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARS 3

int main(int argc, const char *argv[])
{
	uint16_t i = 0;
	char *str = NULL;
	size_t str_size = 0;
	char *file_content = NULL;

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
		}
	}


	/* Warning: hardcoded argv[1] index making this modular would 
	 * help avoid future bugs & would also make this more scalable */
	str_size = strlen(argv[1]);
	str = smalloc(str_size + 1);

	/* write to string */
	strncpy(str, argv[1], str_size);
	str[str_size] = '\0';

	menu(str, str_size);

	free(str);

	return 0;
}
