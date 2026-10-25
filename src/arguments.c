#include "header.h"

#define comp(arg1, arg2) \
	cmp(argument, arg1, arg2);

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
	/* loop on arguments
	 *
	 * match for each type
	 *
	 * return type */
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
