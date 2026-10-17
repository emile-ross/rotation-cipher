#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdint.h>

#include "data_types.h"

#define INT32MAX	(2147483647)
#define INT32MIN	(-2147483648)

void *smalloc(size_t size);
void rotate(char **dst, char *src, size_t len, char *init_char, uint8_t charset, int8_t cipher);
void decipher(char **dst, char *src, size_t *length, cipher_type cipher);
void to_cipher(char **dst, char *src, size_t *length, cipher_type cipher);

/* base64.c */
	unsigned char * base64_encode(const unsigned char *src, size_t len, size_t *out_len);
	unsigned char * base64_decode(const unsigned char *src, size_t len, size_t *out_len);

cipher_type menu(char **str, size_t length);
void display_menu(struct cipher_menu_item *menu_items, cipher_type *types);

/* compare.c */
	Bool scmp(const char *s1, const char *s2);
	Bool cmp(const char *arg, const char *s1, const char *s2);

/* memory_safety.c */
	void *scalloc(size_t n, size_t size);
	void *srealloc(void *old_ptr, size_t size);

/* file_reading.c */
	char *get_file_content(const char *filename);

/* arguments.c */
	uint16_t argtype_to_index(const int32_t num_args, const argument_type *args, const argument_type type);


/* take_input.c */
	int32_t getinput(input_types *action);
	void block(void);

/* string copy */
	void safe_mem_copy(char *dst, size_t *dst_size, char *src, size_t src_size);


/* in main.c */
	void display_help(void);
