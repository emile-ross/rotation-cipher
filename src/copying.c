#include "header.h"

#include <stdlib.h>

Bool copy(const char *input)
{
	const char *command_template = "echo -en \"%s\" | %s";
	char *clipboard = NULL;
	uint32_t size = 0;
	char *cmd_buf = NULL;

	#ifdef _WIN32
		char *win_clip = "clip";
		clipboard = win_clip;
	#else
		if (xorg)
		{
			char *xclip = "xclip";
			clipboard = xclip;
		}
		else if (wayland)
		{
			char *wlcopy = "wl-copy";
			clipboard = wlcopy;
		}
	#endif

	size = 1 + (unsigned)snprintf(NULL, 0, command_template, input, clipboard);
	cmd_buf = smalloc(size);

	snprintf(cmd_buf, size, command_template, input, clipboard);

	system(cmd_buf);
	free(cmd_buf);

	return True;
}
