#include "header.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

Bool bound(const char c, const int lb, const int charset);

/* init_char is the first char in the charset, charset is the number of characters
 * in the charset, cipher is the size of the shift */
void rotate(char *str, size_t len, char *init_char, uint8_t charset, int8_t cipher)
{
	size_t num_charsets = strlen(init_char);
	char *temp = smalloc(len + 1);	/* +1 for NULL terminator */
	char c = '\0';
	size_t i = 0;	/* used as an iterator */
	size_t j = 0;	/* used as an iterator */
	Bool swapped = False;

	for (i = 0; i < len; i++)
	{
		swapped = False;
		for (j = 0; j < num_charsets; j++)
		{
			if (bound(str[i], init_char[j], charset))
			{
				c = str[i] - init_char[j];
				c += cipher;
				c %= (char)charset;
				temp[i] = c + init_char[j];
				swapped = True;
				break;
			}
		}

		if (!(swapped))
		{
			temp[i] = str[i];
		}
	}

	/* copy over data to the str */
	strncpy(str, temp, len);
	str[len] = '\0';	/* NULL terminate the string */

	free(temp);	/* temp isn't needed anymore */
}

Bool bound(const char c, const int lb, const int charset)
{
	/* the c char is within the bounds */
	if (c >= lb && c < (lb + charset))
	{
		return True;
	}
	return False;
}
