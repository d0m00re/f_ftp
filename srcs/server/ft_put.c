#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>
#include <sys/socket.h>
#include "setting.h"

int ft_put(t_server *server)
{
	int c;

	c = 0;
	// premiere etape
	server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
	ft_file_write_begin(server->sp_buffer[1], &(server->buffer[(size_t)server->len_header]), (size_t)server->size_buf - server->len_header);
	send(server->sock, "200", 3, 0);
	while (!c)
	{
		ft_putstr("TURN AROUND THE WORLD ....\n");
		// penser a ajouter un control de parametre si un petit con s amuse trop ...
		server->size_buf = recv(server->sock, server->buffer, SIZE_BUF, 0);
		// case where we write in the thile
		if (server->size_buf > 3) // when we have data bitch 
		{
			server->num_built_old = server->num_built;
			server->sp_buffer = ft_strsplit_nb_word(server->buffer, ' ', &(server->size_sp));
			server->num_built = find_builtin(server->sp_buffer[0]);
			if (server->num_built == PUT && server->size_sp > 2)
				ft_file_write_end(server->sp_buffer[1], &(server->buffer[(size_t)server->len_header]), ((size_t)server->size_buf - server->len_header));			
			else
				ft_putstr("|||||||||||| Error ...\n");
		}
		else
			c = 1;
		// on attein ce cas dans le cas lorsque l on arrive dans le cas ou on nous envoi juste le put
		send(server->sock, "200", 3, 0);
		//case where we end this sheat
	}
	return (1);
}
