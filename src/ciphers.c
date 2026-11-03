#include "header.h"

#include <stdlib.h>
#include <string.h>

char *cipher_type_text(cipher_type type)
{
	switch (type)
	{
		case ROT_47:
			return "ROT-47";
		case ROT_48:
			return "ROT-48";
		case ROT_1:
			return "ROT-1";
		case ROT_24:
			return "ROT-24";
		case ROT_13:
			return "ROT-13";
		case BASE_64:
			return "ROT-64";
		case HEX:
			return "HEX";
		case RSA:
			return "RSA PUB";
		case ALPHA_NUM:
			return "ALPHA NUM";
		case previous_cipher:
		case undefined:
		default:
			return "(Unknown cipher name)";
	}
	return NULL;
}
