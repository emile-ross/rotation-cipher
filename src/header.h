#include <stdio.h>
#include <stdint.h>

#include "data_types.h"

void *smalloc(size_t size);
void rotate(char **dst, char *src, size_t len, char *init_char, uint8_t charset, int8_t cipher);
void decipher(char **dst, char *src, size_t length, cipher_type cipher);

/* base64.c */
	unsigned char * base64_encode(const unsigned char *src, size_t len, size_t *out_len);
	unsigned char * base64_decode(const unsigned char *src, size_t len, size_t *out_len);

void menu(char *str, size_t length);
void display_menu(struct cipher_menu_item *menu_items, cipher_type *types);
