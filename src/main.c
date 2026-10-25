#include "header.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ARS (3)
#define NUM_DEPTH_INCR (4)

#define next_arg(file_path) \
	args[i] = used_flag; \
	if (i + 1 < argc) { \
		file_path = strdup(argv[i + 1]); \
		if (file_path == NULL) { \
			fprintf(stderr, "error: strdup() returned NULL (failed to allocate memory)\n"); \
			return 1; } \
		args[i + 1] = used_argument; \
	} else { \
		args_expected(argv[i]); \
		return -2; \
	}

int main(int argc, const char *argv[])
{
	uint16_t i = 0;
	char *str = NULL;	/* gets edited by the menu() fn & main() */
	uint16_t unused_arg_count = 0;
	size_t temp_length = 0;
	char *src_file_path = NULL;
	char *dst_file_path = NULL;
	char *user_cipher_str = NULL;
	uint16_t temp_index = 0;

	cipher_type prev_cipher_type = undefined;
	cipher_type user_cipher = undefined;
	input_types action = MENU_INVALID;

	argument_type *args = smalloc(sizeof(argument_type) * (unsigned)argc);
	args[0] = file_executed;	/* the command executing this */

	if (argc <= 1)
	{
		fprintf(stderr, "Insufficient arguments | Arguments insuffisants\n");
		free(args);	/* free on exit */
		return -5;
	}

	for (i = 1; i < argc; i++)
	{
		if (scmp(argv[i], "--src-file") || cmp(argv[i], "-f", "--file"))
		{
			next_arg(src_file_path);
		}
		else if (cmp(argv[i], "--dst-file", "--destination-file") || cmp(argv[i], "-d", "--destination"))
		{
			next_arg(src_file_path);
		}
		else if (cmp(argv[i], "-c", "--cipher"))
		{
			args[i] = used_flag;
			if (i + 1 < argc)
			{
				/* TODO determine the type of cipher */
			}
			else
			{
				args_expected(argv[i]);
				return -1;
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
				args_expected(argv[i]);
				return -3;
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

	/* if source file path is defined we parse the file */
	if (src_file_path != NULL)
	{
		char *ret = file_handling(src_file_path, dst_file_path, cipher);
		if (ret == NULL)
		{
			fprintf(stderr, "file_handling() failed and returned NULL\n");
			free(args);
			return 1;
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
			"  -c, --cipher\n"
			"         specify the type of cipher/encoding to use\n"
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
