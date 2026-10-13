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
	int c = 0;
	size_t i = 0;	/* used as an iterator */
	size_t j = 0;	/* used as an iterator */

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < num_charsets; j++)
		{
			if (bound(str[i], init_char[j], charset))
			{
				c = str[i] - init_char[j];
				c = ((c + cipher) % charset + charset) % charset;
				str[i] = (char)c + init_char[j];
				break;
			}
		}
	}
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

void decipher(char *str, cipher_type cipher)
{
	switch(cipher)
	{
		case ROT_48:
			rotate(str, strlen(str), "!", 48, -24);
			break;

		case ROT_13:
			rotate(str, strlen(str), "aA", 26, 13);
			break;

		case RSA:
			fprintf(stderr, "RSA is not supported. yet...\n");
			break;

		case undefined:
		default:
			break;
	}
}
