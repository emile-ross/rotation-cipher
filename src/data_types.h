typedef enum
{
	undefined = 0,
	ROT_1,
	ROT_13,
	ROT_24,
	ROT_47,
	ROT_48,
	BASE_64,
	RSA
} cipher_type;

typedef enum
{
	False = 0,
	True = 1
} Bool;

typedef struct cipher_menu_item
{
	struct cipher_menu_item *next;
	cipher_type type;
	char *plain_text;
	size_t string_length;
} cipher_menu_item;

typedef enum
{
	unknown_type = 0,
	file_executed,
	used_flag,
	used_argument,
	unused_argument
} argument_type;
