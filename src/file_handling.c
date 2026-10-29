#include "header.h"

#include <string.h>
#include <stdlib.h>

/* read from file and return a pointer to the allocated memory */
Bool file_handling(const char *filename, char *dst_filename, cipher_type *cipher)
{
	const size_t LINE_BUFFER_SIZE = 512; 

	FILE *fp = NULL;
	FILE *dst_fp = NULL;

	char *input_buffer = NULL;	/* used as a temporary buffer for the line */
	char *s_dst_filename = NULL;
	size_t dst_len = 0;
	const char *filename_template = "temp-%s";

	if (dst_filename != NULL)
	{
		if (scmp(dst_filename, filename))
		{
			dst_len = (unsigned)snprintf(NULL, 0, filename_template, dst_filename);
			s_dst_filename = smalloc(dst_len + 1);
			snprintf(s_dst_filename, dst_len + 1, filename_template, dst_filename);
			dst_fp = fopen(s_dst_filename, "w");

			if (dst_fp == NULL)
			{
				fprintf(stderr, "fopen() failed to \"%s\"\n", s_dst_filename);

				free(s_dst_filename);
				return False;
			}
		}
		else
		{
			s_dst_filename = dst_filename;
		}
	}

	/* open file in reading 
	 * file will never be written to directly 
	 * if the dst_filename is defined, we open another temporary file &
	 * then replace the original file with the destination one */
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "No such file \'%s\' | Aucun fichier nommé: \'%s\'\n", 
				filename, filename);
		if (s_dst_filename != NULL)
			free(s_dst_filename);

		return False;
	}

	input_buffer = smalloc(LINE_BUFFER_SIZE + 1);
	while (1)
	{
		size_t length = LINE_BUFFER_SIZE;
		char *dst = NULL;

		if (fgets(input_buffer, (int32_t)LINE_BUFFER_SIZE, fp) != NULL)
		{
			/* decipher and then write to new file (if needed) */
			decipher(&dst, input_buffer, &length, *cipher);

			if (dst_filename != NULL)
			{
				/* TODO write to file */
				fprintf(dst_fp, "%s", input_buffer);
			}
			else
			{
				printf(input_buffer);
			}
		}
		else
		{
			break;
		}
	}

	free(input_buffer);

	if (s_dst_filename != NULL)
	{
		free(s_dst_filename);
		fclose(dst_fp);
	}

	return False;
}
