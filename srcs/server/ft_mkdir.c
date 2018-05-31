#include "ft_string.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int ft_mkdir(t_server *server)
{
	printf("--> server->buffer : %s\n", server->buffer);
	mkdir(server->sp_buffer[1], 0777);
	// mise a jours du repertoire
	return (0);
}
