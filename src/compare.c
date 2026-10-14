#include "header.h"

Bool scmp(const char *s1, const char *s2)
{
	uint16_t i = 0;
	for (i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
		{
			return False;
		}
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return True;
	}
	else
	{
		return False;
	}
}
