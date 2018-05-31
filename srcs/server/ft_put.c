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

/*int ft_put(char *name, char *data, unsigned int size, t_server_integ *serv)
{
	char *path_name;
	int c;

	c = 0;
	// decomposition de l url pout garder que le nom de fichier
	//path_name = ft_concat_with_sep(serv->full_path_server, name, ".");
//	path_name = generate_path_server_with_name(serv, name);
//	printf("-> %s\n%s\n%s\n", serv->full_path_server, name, path_name);
//
//	printf("*put : path generate : %s\n", path_name);
//	exit(1);
	ft_file_write_end(path_name, data, size);
	return (1);
}
*/
