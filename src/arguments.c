#include "header.h"

#define comp(arga, argb) \
	cmp(argument, arga, argb)

uint16_t argtype_to_index(const int32_t num_args, const argument_type *args, const argument_type type)
{
	uint16_t i;
	for (i = 1; i < num_args; i++)
	{
		if (args[i] == type)
		{
			return i;
		}
	}
	return 0;
}


cipher_type convert_to_cipher(const char *argument)
{
	if (comp("64", "base-64") || 
			comp("B64", "BASE64") ||
			comp("b64", "base64") ||
			comp("BASE_64", "BASE-64"))
	{
		return BASE_64;
	}
	else if (comp("ROT-13", "ROT_13") || comp("rot-13", "13"))
	{
		return ROT_13;
	}
	else if (comp("ROT-24", "ROT_24") || comp("rot-24", "24"))
	{
		return ROT_24;
	}
	else if (comp("ROT-1", "ROT_1") || comp("rot-1", "1"))
	{
		return ROT_1;
	}
	fprintf(stderr, "Invalid cipher used\n");

	printf("here are all valid cipher types: \n");
	printf("BASE-64\nROT-1\nROT-13\nROT-24\nROT-48\n");
	return undefined;
}
/* 
{
	undefined = 0,
	previous_cipher = 1,
	ROT_1,
	ROT_13,
	ROT_24,
	ROT_47,
	ROT_48,
	BASE_64,
	RSA
} cipher_type;
*/
