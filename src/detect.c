#include "header.h"


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
		return xorg;
	else if (iswsl())
		return wsl;

}
