#include "header.h"

#include <stdlib.h>
#define INIT_MENU_ITEMS (4)

void menu(char *str, size_t length)
{
	struct cipher_menu_item *menu_items = (struct cipher_menu_item*)calloc(INIT_MENU_ITEMS, sizeof(cipher_menu_item));
	uint32_t i = 0;

	cipher_type types[5] = 
	{
		ROT_1,
		ROT_13,
		ROT_48,
		undefined
	};

	for (i = 0; types[i] != undefined; i++)
	{
		decipher(&(menu_items[i].plain_text), str, length, types[i]);
	}
	types[i] = undefined;


	printf("converting %s\n", str);
	display_menu(menu_items, types);
	for (i = 0; types[i] != undefined; i++)
	{
		free(menu_items[i].plain_text);
	}
	free(menu_items);
}

void display_menu(struct cipher_menu_item *menu_items, cipher_type *types)
{
	uint32_t i = 0;
	for (i = 0; types[i] != undefined; i++)
	{
		printf("Item #%u: \'%s\'\n", i + 1, menu_items[i].plain_text);
	}
}
