#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>
#include <sys/socket.h>

int ft_pwd(t_server *server)
{
	char *new;

	new = extract_string_diff(server->full, server->actual);
	if (!new)
		new = ft_strdup("/");
	ft_strcpy(server->buffer, "200 ");
	ft_strcat(server->buffer, new);
	send(server->sock, server->buffer, ft_strlen(server->buffer), 0);
	return (1);
}

