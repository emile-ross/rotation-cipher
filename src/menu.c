#include "header.h"

#include <stdlib.h>
#include <string.h>


#define INIT_MENU_ITEMS (6)

#define DISPLAY_MENU() \
	printf("Converting %s\n", *str); \
	display_menu(menu_items, types);

void menu(char **str, size_t length)
{
	uint32_t i = 0;
	int32_t input = 0;
	uint32_t index_picked = 0;
	Bool success = False;

	/* this is a default setting for the menu and it will never change */
	cipher_type types[INIT_MENU_ITEMS] = 
	{
		ROT_1,
		ROT_13,
		ROT_48,
		BASE_64,
		undefined
	};

	uint32_t num_items = 0;
	struct cipher_menu_item *menu_items = (struct cipher_menu_item*)scalloc(INIT_MENU_ITEMS, sizeof(cipher_menu_item));
	for (i = 0; types[i] != undefined; i++)
	{
		menu_items[i].string_length = length;
		decipher(&(menu_items[i].plain_text), *str, &(menu_items[i].string_length), types[i]);
		num_items++;
	}

	printf("num items: %u\n", num_items);

	
	do 
	{
		display:
		DISPLAY_MENU();
		input = getint(&success);
		if (!(success))
			goto display;
	}
	while (input < 0 || input >= (signed)num_items);
	if (input == 0)
	{
		printf("Exiting...\n");
		free(*str);
		*str = NULL;
		return;
	}
	index_picked = (unsigned)input - 1;

	printf("%s\n", menu_items[index_picked].plain_text);

	free(*str);

	/* write the pointer in the struct to the str in order to avoid copying strings over */
	*str = menu_items[index_picked].plain_text;
	menu_items[index_picked].plain_text = NULL;

	for (i = 0; i < num_items; i++)
	{
		if (i == index_picked)
		{
			continue;
		}
		free(menu_items[i].plain_text);
	}
	free(menu_items);
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
