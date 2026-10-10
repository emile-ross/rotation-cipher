#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	uint16_t i = 0;

	if (argc <= 1)
	{
		fprintf(stderr, "Insufficient arguments | Arguments insuffisants\n");
		return 1;
	}

	/* TODO add file reading */
	if (argc > 2)
	{
		fprintf(stderr, "Unused arguments | Arguments inutiles :\n");
		/* args before index 2 are used 
		 * 0 being cmd, 1 being content / file */

		for (i = 2; i < argc; i++)
			printf("arg %u: \'%s\' \n", i, argv[i]);

		return 1;
	}

	return 0;
}

void rotate(char *str, size_t len, char init_char, int8_t n)
{
	char *temp = malloc(len);
	if (temp == NULL)
	{
		fprintf(stderr, "kernel failed to allocate memory of size %zu\n", len);
		exit(EXIT_FAILURE);
	}
	return;
}
