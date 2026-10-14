#include "header.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

Bool bound(const char c, const int lb, const int charset);

/* init_char is the first char in the charset, charset is the number of characters
 * in the charset, cipher is the size of the shift */
void rotate(char **dst, char *src, size_t len, char *init_char, uint8_t charset, int8_t cipher)
{
	size_t num_charsets = strlen(init_char);
	int c = 0;
	size_t i = 0;	/* used as an iterator */
	size_t j = 0;	/* used as an iterator */

	if (*(dst) == NULL)
	{
		*(dst) = smalloc(len + 1);
	}

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < num_charsets; j++)
		{
			c = '\0';
			if (bound(src[i], init_char[j], charset))
			{
				c = src[i] - init_char[j];
				c = ((c + cipher) % charset + charset) % charset;
				(*dst)[i] = (char)c + init_char[j];
				break;
			} else {
				(*dst)[i] = src[j];
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

void decipher(char **dst, char *src, cipher_type cipher)
{
	/* TODO: avoid recalculation of string length */
	switch (cipher)
	{
		case ROT_48:
			rotate(dst, src, strlen(src), "!", 48, -24);
			break;

		case ROT_13:
			rotate(dst, src, strlen(src), "aA", 26, 13);
			break;

		case RSA:
			fprintf(stderr, "RSA is not supported. yet...\n");
			break;

		case undefined:
		default:
			break;
	}
}
