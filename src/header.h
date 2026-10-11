#include <stdio.h>
#include <stdint.h>


void *smalloc(size_t size);
void rotate(char *str, size_t len, char *init_char, uint8_t charset, int8_t cipher);

typedef enum
{
	False = 0,
	True = 1
} Bool;
