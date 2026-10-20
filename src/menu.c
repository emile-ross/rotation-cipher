#include "header.h"

#include <stdlib.h>
#include <string.h>

/* is replaced everywhere at compile time */
#define INIT_MENU_ITEMS (6)

#define DISPLAY_MENU() \
	printf("\033[2J\033[H"); /* clear */ \
	printf("Converting %s\n", *str); \
	display_menu(menu_items, types);


cipher_type menu(char **str, size_t length, input_types *action, cipher_type prev_cipher_type)
{
	cipher_type ret = undefined;
	uint32_t i = 0;
	int32_t input = 0;
	int32_t index_user_picked = 0;
	char *temp = NULL;
	input_types local_action = MENU_INVALID;

	/* this is a default setting for the menu and it will never change */
	/* TODO create a new config.c file for cipher types */
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
		/* each decipher call will allocate space for the decoded string
		 * and store the pointer in the menu_items array at index 'i' */
		if (menu_items[i].plain_text != NULL)
		{
			num_items++;
		}
	}

	do 
	{
		display:
		DISPLAY_MENU();
		local_action = MENU_INVALID;
		input = getinput(&local_action);
		if (local_action == MENU_INVALID)
			goto display;

		if (local_action == MENU_EXIT)
		{
			break;
		}
		else if (local_action == MENU_UNDO)
		{
			if (prev_cipher_type != undefined)
			{
				break;
			}
			else
			{
				fprintf(stderr, "Cannot undo further\n");
				block();
			}
		}
	}
	while ((input < 0 || input > (signed)num_items));
	/* TODO fix this possibly out of bounds access if the item  */

	if (local_action != MENU_UNDO && local_action != MENU_EXIT)
	{
		if (str != NULL)
		{
			free(*str);
		}
		*str = NULL;
	}

	*action = local_action;

	if (local_action == MENU_ENTRY)
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
		for (i = 0; types[i] != undefined; i++)
		{
			if ((signed)i == index_user_picked && index_user_picked != -1)
				continue;

		}
	}
	else if (local_action == MENU_UNDO)
	{
		to_cipher(&temp, *str, &length, prev_cipher_type);
		/* to cipher returns a region of memory allocated on the heap */
		printf("%s\n", temp);
		strip_newline(temp, length);

		*str = temp;

		/* this will do -1 in the future array of actions in main.c */
		/* free locally allocated struct */
		ret = previous_cipher;
	}

	for (i = 0; types[i] != undefined; i++)
	{
		if (menu_items[i].plain_text != NULL)
			free(menu_items[i].plain_text);
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

void strip_newline(char *string, size_t length)
{
	uint32_t i = 0;
	if (length <= 2)
	{
		return;
	}

	for (i = (uint32_t)length; i > 0; i--)
	{
		if (string[i] == '\n' || string[i] == '\r')
		{
			string[i] = '\0';
		}
		else if (string[i] == '\0')
		{
			continue;
		}
		else 
		{
			break;
		}
	}
}
