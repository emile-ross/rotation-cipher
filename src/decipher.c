#include "header.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

Bool bound(char c, int lb, int charset);

void rotate(char *str, size_t len, char init_char, uint8_t charset, int8_t cipher)
{
	char *temp = smalloc(len + 1);	/* +1 for NULL terminator */
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
		temp[i] = d;
	}

	/* copy over data to the str */
	strncpy(str, temp, len);
	str[len] = '\0';	/* NULL terminate the string */

	free(temp);	/* temp isn't needed anymore */
}

Bool bound(char c, int lb, int charset)
{
	if (c > lb && c < (lb + charset))
	{
		return True;
	}
	return False;
}
