#include "header.h"

#include <stdlib.h>

Bool copy(const char *input)
{
	const char *command_template = "echo -en \"%s\" | %s";
	char *clipboard = NULL;
	uint32_t size = 0;
	char *cmd_buf = NULL;

	server_type display_server = get_server();

	switch (display_server)
	{
		case wsl: {
			clipboard = "clip.exe";
			break;
		}
		case xorg: {
			clipboard = "xclip";
			break;
		}
		case wayland: {
			clipboard = "wl-copy";
			break;
		}
		case windows: {
			clipboard = "clip";
			break;
		}
		default: {
			clipboard = "clip";
		}
	}

	size = 1 + (unsigned)snprintf(NULL, 0, command_template, input, clipboard);
	cmd_buf = smalloc(size);

	snprintf(cmd_buf, size, command_template, input, clipboard);

	system(cmd_buf);
	free(cmd_buf);

	return True;
}
