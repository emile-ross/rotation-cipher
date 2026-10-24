#include "header.h"

#include <string.h>

/* read from file and return a pointer to the allocated memory */
char *file_handling(const char *filename, const char *dst_filename, cipher_type *cipher)
{
	const size_t LINE_BUFFER_SIZE = 512; 

	FILE *fp = NULL;
	FILE *dst_fp = NULL;

	char *input_buffer = NULL;	/* used as a temporary buffer for the line */
	char *s_dst_filename = NULL;
	size_t dst_filename_length = 0;
	const char *str = "temp-";

	if (scmp(dst_filename, filename))
	{
		dst_filename_length = strlen(dst_filename);
		s_dst_filename = smalloc(dst_filename_length + 1 + 5);
		snprintf(s_dst_filename, );
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
		return NULL;
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
			}
			else
			{
			}
		}
		else
		{
			break;
		}
	}
	return NULL;
}
