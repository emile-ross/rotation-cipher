#include "header.h"

/* The display server is used to determine which
 * command to use when copying to the clipboard */
const Bool xorg = True;
const Bool wayland = False;

/* this will exit whenever the user copies something to the clipboard */
const Bool exit_on_copy = False;	

/* when the number of items are modified in the array below, 
 * the INIT_MENU_ITEMS macro definition must be modified in header.h 
 * it is at the top of the file and it looks like this: 
 * #define INIT_MENU_ITEMS (X) */

cipher_type types[INIT_MENU_ITEMS] = 
{
	ROT_1,
	ROT_13,
	ROT_48,
	BASE_64,
	undefined
};
