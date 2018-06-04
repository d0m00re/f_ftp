#include "ft_string.h"
#include "server.h"
#include "ft_file.h"
#include "setting.h"
#include "ft_display.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>

static int check_futur_path(t_server *s)
{
	char *path_to_test;
	char *path;
	size_t size;
	int valid_path;

	// step 1 : recuperer le chemin sans le nom de fichier
	if (!(path = ft_strextract_before_rchr(s->sp_buffer[1], '/')))
		return (0);
	// step 2 : concatener le path du server avec le path actuel
	size = ft_strlen(path) + ft_strlen(s->actual);
	if (!(path_to_test = malloc(sizeof(char) * (size + 2))))
	{
		free(path);
		return (0);
	}
	ft_strcpy(path_to_test, s->actual);
	ft_strcat(path_to_test, "/");
	ft_strcat(path_to_test, path);

	// 3 : checker la validite
	valid_path = valid_path_no_dess(s->full, path_to_test);
	free(path_to_test);
	return (valid_path);
}

int	ft_get(t_server *server)
{
	int ret;
	int fd;
	size_t len;

	ft_putstr("begin get\n");
	if (server->size_sp < 2)
	{
		ft_putstr("Error nb arg.\n");
		send(server->sock, "512", 3, 0);
		return (3);
	}
	ft_putstr("begin futur path get\n");
	if (check_futur_path(server) == 0)
	{
		ft_putstr("--- INVALID PATH\n");
		send(server->sock, "511", 3, 0);
		return (3);
	}
	if (is_file(server->sp_buffer[1]) == 0)
	{
		ft_putstr("---  IS NOT A FILE\n");
		send(server->sock, "513", 3, 0);
		return (3);
	}
	ft_putstr("other ....\n");
	server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
	if ((fd = open(server->sp_buffer[1], O_RDONLY)) == -1)
	{
		ft_putstr("--- INVALD FILE\n");
		send(server->sock, "714", 3, 0);
		return (3);
	}
	while ((len = read(fd, &(server->buffer[server->len_header]), SIZE_BUF - server->len_header)) > 0)
	{
		if ((send(server->sock, server->buffer, len + server->len_header, 0)) == -1) // send data to server
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		ret = recv(server->sock, server->buffer, SIZE_BUF, 0);
		concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
	}
	ft_strcpy(server->buffer, "200");
	send(server->sock, server->buffer, 3, 0);
	close(fd);
	return (3);
}
