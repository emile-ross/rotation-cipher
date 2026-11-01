#include "header.h"

#include <stdlib.h>

server_type get_server(void)
{
	const char *environment = getenv("XDG_SESSION_TYPE");

	if (environment == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (scmp(environment, "wayland"))
	{
		return wayland;
	}
	else if (scmp(environment, "xorg"))
	{
		return xorg;
	}
	else if (iswsl())
	{
		return wsl;
	}

	#ifndef _WIN32
		return windows;
	#endif
	
	fprintf(stderr, "Unknown display server\n");
	fprintf(stderr, "Are you running one?\n");

	exit(EXIT_FAILURE);
}

Bool iswsl(void)
{
	/* returns NULL if it fails (not Windows Subsystem for Linux) */
	const char *wsl = getenv("WSL_DISTRO_NAME");

	if (wsl == NULL)
	{
		return False;
	}
	else 
	{
		return True;
	}
}
