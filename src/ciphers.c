#include "header.h"

#include <stdlib.h>
#include <string.h>

char *cipher_type_text(cipher_type type)
{
	const char *str = NULL;
	char *return_string = NULL;
	size_t len = 0;
	switch (type)
	{
		case ROT_47:
			str = "ROT-47";
			break;
		case ROT_48:
			str = "ROT-48";
			break;
		case ROT_1:
			str = "ROT-1";
			break;
		case ROT_24:
			str = "ROT-24";
			break;
		case ROT_13:
			str = "ROT-13";
			break;
		case BASE_64:
			str = "ROT-64";
			break;
		case RSA:
			str = "RSA PUB";
			break;
		case previous_cipher:
		case undefined:
		default:
			fprintf(stderr, "(Unknown cipher name)");
			break;
	}

	if (str != NULL)
	{
		len = strlen(str) + 1;
		return_string = smalloc(len);
		snprintf(return_string, len, "%s", str);
	}
	else
	{
		/* did not write to str in the switch (because it failed) */
		exit(EXIT_FAILURE);	/* TODO handle error in calling function maybe */
	}

	return return_string;
}
