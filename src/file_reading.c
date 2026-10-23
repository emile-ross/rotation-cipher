#include "header.h"

#include <string.h>

/* read from file and return a pointer to the allocated memory */
char *get_file_content(const char *filename)
{
	FILE *fp = NULL;
	char *input_buffer = NULL;
	size_t input_buffer_size = 512; 
	size_t buffer_size_increment = 512;
	size_t increment = 0;

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
		if (fgets((input_buffer + increment), (int32_t)input_buffer_size, fp) != NULL)
		{
			/* decipher and then write to new file */
		}
		else
		{
			break;
		}
	}
	return NULL;
}
