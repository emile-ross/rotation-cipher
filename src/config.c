#ifndef CONFIG_DOT_H
#define CONFIG_DOT_H

#include "header.h"

/* The display server is used to determine which
 * command to use when copying to the clipboard */
const Bool xorg = True;
const Bool wayland = False;

/* this will exit whenever the user copies something to the clipboard */
const Bool exit_on_copy = False;	


cipher_type types[INIT_MENU_ITEMS] = 
{
	ROT_1,
	ROT_13,
	ROT_48,
	BASE_64,
	undefined
};

#endif /* CONFIG_H */
