void rotate(char *str, size_t len, char init_char, uint8_t charset, int8_t cipher)
{
	char *temp = smalloc(len + 1);	/* +1 for NULL terminator */
	size_t i = 0;

	for (i = 0; i < len; i++)
	{
	}

	/* copy over data to the str */
	strncpy(str, temp, len);
	str[len] = '\0';	/* NULL terminate the string */

	free(temp);	/* temp isn't needed anymore */
}
