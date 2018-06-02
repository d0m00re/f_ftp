#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <stdio.h>
#include <sys/socket.h>
#include "setting.h"
#include <stdlib.h>
#include "ft_string.h"

char *main_server(t_server *server)
{
	int value_ret;

	server->size_buf = recv(server->sock, server->buffer, SIZE_BUF, 0);
	server->num_built_old = server->num_built;
	server->sp_buffer = ft_strsplit_nb_word(server->buffer, ' ', &(server->size_sp));
	server->num_built = find_builtin(server->sp_buffer[0]);
	if (server->num_built)
	{
		ft_putstr("We have good bultin.\n");
		if (server->num_built == PUT)
			ft_put(server);
		else if (server->num_built == GET)
			ft_putstr("get\n");
		else if (server->num_built == PWD)
			ft_pwd(server);
		else if (server->num_built == CD)
			ft_cd(server);
		else if (server->num_built == LS)
			ft_ls(server);
		else if (server->num_built == QUIT)
			ft_quit(server);
		else if (server->num_built == MKDIR)
			ft_mkdir(server);
		else
			send(server->sock, "500", 3, 0);
	}
	else
	{
		ft_putstr("We have wrong builtin.\n");
		printf("--> %s|%s\n", server->buffer, server->sp_buffer[0]);
		send(server->sock, "500", 3, 0);
	}
	return (0);
}
