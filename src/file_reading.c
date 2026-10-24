#include "header.h"

#include <string.h>

/* read from file and return a pointer to the allocated memory */
char *file_handling(const char *filename, const char *dst_filename)
{
	const size_t LINE_BUFFER_SIZE = 512; 

	FILE *fp = NULL;
	char *input_buffer = NULL;
	size_t input_buffer_size = 512; 

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
	input_buffer = scalloc(1, input_buffer_size);

	while (1)
	{
		char *dst = NULL;

		if (fgets(input_buffer, (int32_t)line_buffer_size, fp) != NULL)
		{
			/* decipher and then write to new file (if needed) */
			decipher(&dst, input_buffer, size_t *length, cipher_type cipher);

		}
		else
		{
			break;
		}
	}
	return NULL;
}
