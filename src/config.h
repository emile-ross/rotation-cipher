#ifndef CONFIG_H
#define CONFIG_H

#include "header.h"

/* The display server is used to determine which
 * command to use when copying to the clipboard */
static const Bool xorg = True;
static const Bool wayland = False;

/* this will exit whenever the user copies something to the clipboard */
static const Bool exit_on_copy = False;	

#define INIT_MENU_ITEMS (5)
static cipher_type types[INIT_MENU_ITEMS] = 
{
	ROT_1,
	ROT_13,
	ROT_48,
	BASE_64,
	undefined
};

#endif /* CONFIG_H */
