#include "ft_string.h"
#include "server.h"
#include "ft_file.h"
#include "setting.h"
#include "ft_display.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>

int	ft_get(t_server *server)
{
	int ret;
	int fd;
	size_t len;

	if (server->size_sp < 2)
	{
		ft_putstr("Error nb arg.\n");
		return (0);
	}
	server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
	fd = open(server->sp_buffer[1], O_RDONLY);
	while ((len = read(fd, &(server->buffer[server->len_header]), SIZE_BUF - server->len_header)) > 0)
	{
		if ((send(server->sock, server->buffer, len + server->len_header, 0)) == -1) // send data to server
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		ret = recv(server->sock, server->buffer, SIZE_BUF, 0);
		concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
	}
	ft_strcpy(server->buffer, "get");
	send(server->sock, server->buffer, 3, 0);
	close(fd);
	return (1);
}
