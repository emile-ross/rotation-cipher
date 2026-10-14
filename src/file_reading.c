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
	size_t temp = 0;

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
			if (input_buffer[input_buffer_size - 1] != '\0')
			{
				input_buffer_size += buffer_size_increment;
				input_buffer = srealloc(input_buffer, input_buffer_size + 1);
				input_buffer[input_buffer_size] = '\0';
				input_buffer[input_buffer_size - 1] = '\0';
				buffer_size_increment <<= 1;
				if (buffer_size_increment > 12000)
				{
					fprintf(stderr, "Invalid size greater than 12000 bytes\n");
					return NULL;
				}
			}

			temp = strcspn(input_buffer, "\n");
			if (input_buffer[temp] != '\n')
			{
				input_buffer = srealloc(input_buffer, temp + 1);
				return input_buffer;
			}

			increment += temp;
		}
		else
		{
			break;
		}
	}
	return NULL;
}
