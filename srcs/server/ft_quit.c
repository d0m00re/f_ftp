#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "setting.h"

int	ft_quit(t_server *server)
{
	server->running = 0;
	ft_strcpy(server->buffer, END_CLIENT);
	send(server->sock, server->buffer, 3, 0);
	return (1);
}
