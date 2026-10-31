#include "header.h"


char *cipher_type_text(cipher_type type)
{
	switch (type)
	{
		case ROT_47:
			break;
		case ROT_48:
			break;
		case ROT_1:
			break;
		case ROT_24:
			break;
		case ROT_13:
			break;
		case BASE_64:
			break;
		case RSA:
			break;
		case previous_cipher:
			break;
		case undefined:
		default:
			break;
	}
	return NULL;
}
