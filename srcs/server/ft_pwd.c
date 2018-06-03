#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>

int ft_pwd(t_server *server)
{
	char *new;

	new = 0;
	if (server->full == 0)
		ft_putstr("---> Server full is empty ... fuck off\n");
	if (server->actual == 0)
		ft_putstr("---> Server actual is empty ... fuck off");
	new = extract_string_diff(server->full, server->actual);
	printf("server full : %s\n", server->full);
	printf("server actual : %s\n", server->actual);
	if (!new)
		new = ft_strdup("/");
	printf("server new : %s\n", new);
	ft_strcpy(server->buffer, "200 ");
	ft_strcat(server->buffer, new);
	send(server->sock, server->buffer, ft_strlen(server->buffer), 0);
	free(new);
	return (0);
}
