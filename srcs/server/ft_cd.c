#include "ft_string.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int ft_cd(t_server *server)
{
	printf("--> server->buffer : %s\n", server->buffer);
	chdir(server->sp_buffer[1]);
	mkdir("cd_works_bitch", 0777);
	// mise a jours du repertoire
	return (0);
}
