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

	ft_putstr("--------======= SERVER - GET =======-----------------");
	if (server->size_sp < 2) //error nb arg
	{
		ft_putstr("Error nb arg.\n");
	}
	server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
	ft_strcpy(server->buffer, server->sp_buffer[0]);
	ft_strcat(server->buffer, " ");
	ft_strcat(server->buffer, server->sp_buffer[1]); 
	ft_strcat(server->buffer, " "); // put file data put [name] 
	fd = open(server->sp_buffer[1], O_RDONLY);
	while ((len = read(fd, &(server->buffer[server->len_header]), SIZE_BUF - server->len_header)) > 0)
	{
		printf("--=== TURN SERVER ===--\n");
		if ((send(server->sock, server->buffer, len + server->len_header, 0)) == -1) // send data to server
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		ret = recv(server->sock, server->buffer, SIZE_BUF, 0);
		ft_strcpy(server->buffer, server->sp_buffer[0]);
		ft_strcat(server->buffer, " ");
		ft_strcat(server->buffer, server->sp_buffer[1]); 
		ft_strcat(server->buffer, " ");

	}
	ft_strcpy(server->buffer, "get");
	send(server->sock, server->buffer, 3, 0);
	close(fd);
	return (1);
}
