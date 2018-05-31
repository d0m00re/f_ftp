#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <stdio.h>
#include <sys/socket.h>
#include "setting.h"
#include <stdlib.h>

char *main_server(t_server *server)
{
	server->size_buf = recv(server->sock, server->buffer, SIZE_BUF, 0);
	server->num_built_old = server->num_built;
	server->sp_buffer = ft_strsplit_nb_word(server->buffer, ' ', &(server->size_sp));
	server->num_built = find_builtin(server->sp_buffer[0]);
	if (server->num_built)
	{
		ft_putstr("We have good bultin.\n");
		if (server->num_built == PUT)
		{
			server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
			ft_put(server);
			send(server->sock, "200", 3, 0);
		}
		else
			send(server->sock, "500", 3, 0);
	}
	else
	{
		ft_putstr("We have wrong builtin.\n");
		send(server->sock, "500", 3, 0);
	}
	return (0);
}

/*
char	*main_server2(int sock, char *buf, int size, t_server_integ *serv)
{
	int nb_word;
        char *str;
        char **strsp;
        int num_builtins;
	int ret;
	size_t len_header;

	// 1 recevoir le message
	// verif retour code
	ret = recv(sock, buf, SIZE_BUF, 0);
	strsp = ft_strsplit_nb_word(buf, ' ', &nb_word);
	num_builtins = find_builtin(strsp[0]);
	if (num_builtins)
	{
		ft_putstr_limit(buf, 100);
		ft_putstr("Good we have a builtin :)\n");
		if (num_builtins == PUT)// && nb_word >= 3)
		{
			len_header = ft_strlen(strsp[0]) + ft_strlen(strsp[1]) + 2; // get size header
			ft_put(strsp[1], &(buf[len_header]), ret - len_header, serv);
			send(sock, "200", 3, 0);
		}
		else
			send(sock, "500", 3, 0);
	}
        else
	{
                ft_putstr("Builtins not reconize :\n");
		ft_putstr_limit(buf, 20);
		send(sock, "500", 3, 0);
	}
        return (0);
}
*/
