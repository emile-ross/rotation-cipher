#include "header.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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
