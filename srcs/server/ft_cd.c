#include "ft_string.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

/*
** moove in rep specified
** modification of localisation variable
*/

int ft_cd(t_server *server)
{
	if (server->size_sp != 2)
		ft_strcpy(server->buffer, "510");
	else if ((chdir(server->sp_buffer[1])) == -1)
		ft_strcpy(server->buffer, "511");
	else
	{
		if (server->actual)
			free(server->actual);
		server->actual = getcwd(malloc(1024), 1024);
		ft_strcpy(server->buffer, "200");
	}
	send(server->sock, server->buffer, 3, 0);
	return (0);
}
