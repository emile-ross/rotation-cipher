#include "header.h"

#include <stdlib.h>
#include <string.h>

#define INIT_MENU_ITEMS (4)

#define DISPLAY_MENU() \
	printf("Converting %s\n", str); \
	display_menu(menu_items, types);

void menu(char *str, size_t length)
{
	uint32_t i = 0;
	int32_t input = 0;
	Bool success = False;

	/* this is a default setting for the menu and it will never change */
	cipher_type types[6] = 
	{
		ROT_1,
		ROT_13,
		ROT_48,
		BASE_64,
		undefined
	};

	do
	{
		struct cipher_menu_item *menu_items = (struct cipher_menu_item*)scalloc(INIT_MENU_ITEMS, sizeof(cipher_menu_item));
		for (i = 0; types[i] != undefined; i++)
		{
			menu_items[i].string_length = length;
			decipher(&(menu_items[i].plain_text), str, &(menu_items[i].string_length), types[i]);
		}
		types[i] = undefined;

		do
		{
			DISPLAY_MENU();
			input = getint(&success);
			/* getint() has blocking behaviour */
		}
		while (!(success) || input < 0 || input > (signed)i);
		/* validate user input and ensure it is within bounds */

		printf("Valid input \n");
		if (input != 0)
		{
			input--;
			safe_mem_copy(str, &length, menu_items[input].plain_text, strlen(menu_items[input].plain_text));
		}

		/* free all menu items & menu_items */
		for (i = 0; types[i] != undefined; i++)
		{
			free(menu_items[i].plain_text);
		}
	}
	while (input != 0);
	printf("Exiting...\n");
}

void display_menu(struct cipher_menu_item *menu_items, cipher_type *types)
{
	uint32_t i = 0;
	for (i = 0; types[i] != undefined; i++)
	{
		if (types[i] == BASE_64)
		{
			if (menu_items[i].plain_text == NULL)
				continue;
		}
		printf("Item #%u: \'%s\'\n", i + 1, menu_items[i].plain_text);
	}
}
