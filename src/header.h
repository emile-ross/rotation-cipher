#include <stdio.h>
#include <stdint.h>


typedef enum
{
	undefined = 0,
	ROT_13,
	ROT_48,
	RSA
} cipher_types;

void *smalloc(size_t size);
void rotate(char *str, size_t len, char *init_char, uint8_t charset, int8_t cipher);
void decipher(char *str, cipher_types cipher);

/* base64.c */
	unsigned char * base64_encode(const unsigned char *src, size_t len, size_t *out_len);

typedef enum
{
	False = 0,
	True = 1
} Bool;
