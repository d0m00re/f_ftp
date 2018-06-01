#include "ft_string.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/*
** moove in rep specified
** modification of localisation variable
*/

int ft_cd(t_server *server)
{
	printf("--> server->buffer : %s\n", server->buffer);
	chdir(server->sp_buffer[1]);
	if(server->actual)
	{
		free(server->actual);
		server->actual = getcwd(malloc(1024), 1024);
	}
	//mkdir("cd_works_bitch", 0777);
	// mise a jours du repertoire
	return (0);
}
