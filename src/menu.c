#include "header.h"

#include <stdlib.h>
#define INIT_MENU_ITEMS (4)

void menu(char *str, size_t length)
{
	struct cipher_menu_item *menu_items = (struct cipher_menu_item*)calloc(INIT_MENU_ITEMS, sizeof(cipher_menu_item));
	uint32_t i = 0;

	cipher_type types[3] = 
	{
		ROT_13,
		ROT_48,
		undefined
	};

	for (i = 0; types[i] != undefined; i++)
	{

		decipher(menu_items[i]->plain_text, str, types[i]);
	}
}
