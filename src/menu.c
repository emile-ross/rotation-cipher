#include "header.h"

#include <stdlib.h>
#include <string.h>


/* is replaced everywhere at compile time */
#define INIT_MENU_ITEMS (6)

#define DISPLAY_MENU() \
	printf("\033[2J\033[H"); /* clear */ \
	printf("Converting %s\n", *str); \
	display_menu(menu_items, types);

#define FREE_ALL() \
	for (i = 0; i < num_items; i++) \
		free(menu_items[i].plain_text); \
	free(menu_items);

cipher_type menu(char **str, size_t length)
{
	cipher_type ret = undefined;
	uint32_t i = 0;
	int32_t input = 0;
	int32_t index_user_picked = 0;
	input_types action = MENU_INVALID;

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
		if (menu_items[i].plain_text != NULL)
		{
			num_items++;
		}
	}

	do 
	{
		display:
		DISPLAY_MENU();
		action = MENU_INVALID;
		input = getinput(&action);
		if (action == MENU_INVALID)
			goto display;
		if (action == MENU_EXIT)
			break;
	}
	while (input < 0 || input > (signed)num_items);

	free(*str);
	*str = NULL;

	if (action == MENU_ENTRY)
	{
		index_user_picked = input - 1;

		if (index_user_picked >= 0 && index_user_picked < INIT_MENU_ITEMS)
		{
			ret = types[index_user_picked];
		}
		else
		{
			ret = undefined;
		}

		/* write the pointer in the struct to the str in order to avoid copying strings over */
		if (index_user_picked >= 0)
		{
			*str = menu_items[index_user_picked].plain_text;
			menu_items[index_user_picked].plain_text = NULL;
		}
		for (i = 0; i < num_items; i++)
		{
			if ((signed)i == index_user_picked && index_user_picked != -1)
				continue;

			free(menu_items[i].plain_text);
		}
	}
	else if (action == MENU_EXIT)
	{
		FREE_ALL();
		return undefined;
	}

	free(menu_items);
	return ret;
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
