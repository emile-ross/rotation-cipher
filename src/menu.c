#include "header.h"

void menu(char *str, size_t length)
{
	char *menu_items[] = NULL;
	decipher(str, ROT_13);

	decipher(menu_items[1], ROT_13);
	decipher(menu_items[2], ROT_48);
	decipher(str, ROT_48);
}
