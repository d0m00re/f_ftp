#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>


int ft_put(char *name, char *data, unsigned int size, t_server_integ *serv)
{
	char *path_name;
	int c;

	c = 0;
	//path_name = ft_concat_with_sep(serv->full_path_server, name, ".");
	path_name = generate_path_server_with_name(serv, name);
//	printf("-> %s\n%s\n%s\n", serv->full_path_server, name, path_name);
//
	printf("*put : path generate : %s\n", path_name);
//	exit(1);
	ft_file_write_end(path_name, data, size);
	return (1);
}
