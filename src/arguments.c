#include "header.h"

uint16_t argtype_to_index(const int32_t num_args, const argument_type *args, const argument_type type)
{
	uint16_t i = 0;
	for (i = 1; i < num_args; i++)
	{
		if (args[i] == type)
		{
			return i;
		}
	}
	return 0;
}

