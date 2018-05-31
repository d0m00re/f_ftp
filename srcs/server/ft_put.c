#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>

int ft_put(t_server *server)
{
	//ft_putstr_limit(server->buffer  ,1024);
	//ft_putstr_limit(server->buffer, 1024);
	//ft_putstr_limit(&(server->buffer[server->len_header]), (size_t)server->size_buf - server->len_header);
	ft_file_write_end(server->sp_buffer[1], &(server->buffer[(size_t)server->len_header]), (size_t)server->size_buf - server->len_header);
	return (1);
}
