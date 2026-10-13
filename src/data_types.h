typedef enum
{
	undefined = 0,
	ROT_13,
	ROT_48,
	RSA
} cipher_types;

typedef enum
{
	False = 0,
	True = 1
} Bool;

typedef struct cipher_menu_item
{
	struct cipher_menu_item *next;
	char *text;
} cipher_menu_item;
