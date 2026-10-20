#include "header.h"

static const Bool xorg = True;
static const Bool wayland = False;

#define INIT_MENU_ITEMS (5)
static cipher_type types[INIT_MENU_ITEMS] = 
{
	ROT_1,
	ROT_13,
	ROT_48,
	BASE_64,
	undefined
};
