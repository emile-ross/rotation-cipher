#include "header.h"

#include <stdlib.h>
#define INIT_MENU_ITEMS (4)

void menu(char *str, size_t length)
{
	struct cipher_menu_item *menu_items = (struct cipher_menu_item*)scalloc(INIT_MENU_ITEMS, sizeof(cipher_menu_item));
	uint32_t i = 0;

	/* this is a default setting for the menu and it will never change */
	cipher_type types[6] = 
	{
		ROT_1,
		ROT_13,
		ROT_48,
		BASE_64,
		undefined
	};


	for (i = 0; types[i] != undefined; i++)
	{
		menu_items[i].string_length = length;
		decipher(&(menu_items[i].plain_text), str, &(menu_items[i].string_length), types[i]);
	}
	types[i] = undefined;


	printf("Converting %s\n", str);
	display_menu(menu_items, types);

	/* free all menu items & menu_items */
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
