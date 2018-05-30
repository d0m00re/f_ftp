#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

t_server_integ *server_integ_make(char *name_server)
{
	t_server_integ *in;

	if (!(in = malloc(sizeof(*in))))
		return (0);
	in->name_server = strdup(name_server);
	in->full_path = malloc(1024);
	in->full_path_server = malloc(2048);

	if (!(getcwd(in->full_path, 1024)))
		printf("Error ....\n");

	// construction du path complet du server

	strcpy(in->full_path_server, in->full_path);
	strcat(in->full_path_server, "/");
	strcat(in->full_path_server, in->name_server);
	strcat(in->full_path_server, "/");

	// initialisasion du path absolute du server
	in->path_actual = strdup(".");

	in->full_path_actual = generate_path_server(in);

	// mise a zero des element servant a controller le bon etat du serveur

	in->valid_ftp = 0;
	in->valid_path = 0;
	in->rep_is_create = 0;


	return (in);
}
/*
int main()
{
	t_server_integ *i = 0;

	i = server_integ_make("MA_BITE"); // repertoire projet | 
	printf("-> %s\n", i->full_path_server);
	return (1);
}
*/
