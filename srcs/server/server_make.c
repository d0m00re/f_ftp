#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ft_display.h"

// on va creer le repertoire si il n existe pas
int ft_create_rep_if_no_exist(char *server_name)
{
	struct stat sb;

	ft_putstr("*creation server : ");
	ft_putstr(server_name);
	ft_putchar('\n');
	//si le repertoire serveur existe
	if (stat(server_name, &sb) != -1) // dans le cas ou le repertoire n existe pas
		return (1);
	if (mkdir(server_name, 0777) == -1)
		return (1);
	return (1);
}

t_server *server_make(char *server_name)
{
	t_server *server;

	if (!(server = malloc(sizeof(t_server))))
		return (0);
	server->deph = 0;
	server->name = strdup(server_name);
	//server->serveur

	server->valid_ftp = 0;
	server->valid_path = 1;

	// creation du repertoire si il n existe pas
	server->rep_is_create = ft_create_rep_if_no_exist(server_name);

	//moov in the repertories
	chdir(server_name);

	server->full = getcwd(malloc(1024), 1024); // recuperation du path du serveur
	server->actual = strdup(server->full);

	server->valid_ftp = 1;
	server->rep_is_create = 1;

	server->running = 1;
	return (server);
}
