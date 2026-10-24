#include "header.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARS (3)
#define NUM_DEPTH_INCR (4)

int main(int argc, const char *argv[])
{
	uint16_t i = 0;
	char *str = NULL;	/* gets edited by the menu() fn & main() */
	char *file_content = NULL;
	uint16_t unused_arg_count = 0;
	size_t temp_length = 0;
	uint16_t temp_index = 0;
	cipher_type prev_cipher_type = undefined;
	input_types action = MENU_INVALID;

	argument_type *args = smalloc(sizeof(argument_type) * (unsigned)argc);
	args[0] = file_executed;

	if (argc <= 1)
	{
		fprintf(stderr, "Insufficient arguments | Arguments insuffisants\n");
		free(args);	/* free on exit */
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

				args[i + 1] = used_argument;

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
		else if (cmp(argv[i], "-c", "--cipher"))
		{
			args[i] = used_flag;
			if (i + 1 < argc)
			{

			}
			else
			{
				fprintf(stderr, "arguments expected following the \'%s\' flag\n", argv[i]);
			}
		}
		else if (cmp(argv[i], "-s", "--string"))
		{
			args[i] = used_flag;
			if (i + 1 < argc)
			{
				temp_length = strlen(argv[i + 1]);
				str = smalloc(temp_length);
			}
			else
			{
				fprintf(stderr, "arguments expected following the \'%s\' flag\n", argv[i]);
			}
		}
		else if (cmp(argv[i], "-H", "--help"))
		{
			display_help();
		}
		else
		{
			args[i] = unused_argument;
			unused_arg_count++;
		}
	}

	/* get str from the unused argument passed into the program */
	if (str == NULL && unused_arg_count == 1)
	{
	       temp_index = argtype_to_index(argc, args, unused_argument);
	       temp_length = strlen(argv[temp_index]) + 1;
	       str = smalloc(temp_length);
	       strncpy(str, argv[temp_index], temp_length);
	       str[temp_length - 1] = '\0';
	}
	free(args);

	do 
	{
		cipher_type ret = undefined;
		/* prevent undoing twice in a row */
		if (action == MENU_UNDO)
			prev_cipher_type = undefined;

		ret = menu(&str, 1 + strlen(str), &action, prev_cipher_type);
		prev_cipher_type = ret;
	}
	while (prev_cipher_type != undefined);

	if (str != NULL)
	{
		free(str);
	}
	return 0;
}

void display_help(void)
{
	printf(
			"Usage: rot-solver [OPTION]... DIRECTORY...\n"
			"Create the DIRECTORY(ies), if they do not already exist.\n"
			"Mandatory arguments to long options are mandatory for short options too.\n"
			"  -s, --string\n"
			"         specify the string to decode after the flag\n"
			"  -f, --file\n"
			"         reads the ciphertext from a file\n");
}

void args_expected(const char *cmd_flag)
{
	fprintf(stderr, "Arguments expected following the \'%s\' flag\n", cmd_flag);
	fprintf(stderr, "Expected: %s [argument]\n", cmd_flag);
}
