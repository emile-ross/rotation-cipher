#include "header.h"

#define INIT_MENU_ITEMS (4)

void menu(char *str, size_t length)
{
	struct cipher_menu_item *(menu_items[]) = smalloc(sizeof(cipher_menu_item) * INIT_MENU_ITEMS);

	cipher_type types[3] = 
	{
		ROT_13,
		ROT_48,
		undefined
	};

	for (i = 0; types[i] != undefined; i++)
	{
		decipher(menu_items[i]->plain_text, types[i]);
	}
}
