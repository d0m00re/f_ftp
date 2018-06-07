/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 04:08:52 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 04:16:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "server.h"
#include "ft_file.h"
#include "setting.h"
#include "ft_display.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>


static int		check_futur_path(t_server *s)
{
	char		*path_to_test;
	char		*path;
	size_t		size;
	int			valid_path;

	if (!(path = ft_strextract_before_rchr(s->sp_buffer[1], '/')))
		return (1);
	size = ft_strlen(path) + ft_strlen(s->actual);
	if (!(path_to_test = malloc(sizeof(char) * (size + 2))))
	{
		free(path);
		return (0);
	}
	ft_strcpy(path_to_test, s->actual);
	ft_strcat(path_to_test, "/");
	ft_strcat(path_to_test, path);
	valid_path = valid_path_no_dess(s->full, path_to_test);
	free(path_to_test);
	free(path);
	return (valid_path);
}

static int		send_and_return_server(t_server *server,\
			char *str, int size, int ret)
{
	send(server->sock, str, size, 0);
	return (ret);
}

static int		good_param(t_server *server)
{
	if (server->size_sp < 2)
		return (send_and_return_server(server, "521", 3, 3));
	if (check_futur_path(server) == 0)
		return (send_and_return_server(server, "522", 3, 3));
	if (is_file(server->sp_buffer[1]) == 0)
		return (send_and_return_server(server, "523", 3, 3));
	return (0);
}

typedef struct s_get_server
{
	int fd;
	char *cmd;
	char *name_file;
	char *header;

	int len_cmd;
	int len_name;
	int len_header;

	char **sp_buffer;
	int sp_size;

	int len;

	int real_size;
} t_get_server;

t_get_server			*init_get_server(t_server *server)
{
	t_get_server	*gs;

	if (!(gs = malloc(sizeof(t_get_server))))
		return (0);
	if (!(gs->cmd = ft_strdup("get")))
		return (0);
	if (!(gs->name_file = ft_strdup(server->sp_buffer[1])))
		return (0);
	gs->len_cmd = ft_strlen(gs->cmd);
	gs->len_name = ft_strlen(gs->name_file);
        if (!(gs->header = malloc(sizeof(char) * (gs->len_cmd + gs->len_name + 3))))
		return (0);
        concat_2dchar_in_buffer(gs->header, server->sp_buffer, 2, " ");
	gs->len_header = ft_strlen(gs->header);
	gs->sp_buffer = 0;
	gs->sp_size = 0;
	gs->real_size = 0;
	gs->fd = 0;
	return (gs);
}

void			destroy_get_server(t_get_server *s)
{
	free(s->cmd);
	free(s->name_file);
	free(s->header);
	free(s);
}

int				ft_get(t_server *server)
{
//	size_t		len;
	t_get_server *s;

	printf("Begining ....\n");
	if (good_param(server))
		return (3);
	s = init_get_server(server);
	printf("NAME FILE : %s\n", s->name_file);
	if ((s->fd = open(s->name_file, O_RDONLY)) == -1)
		return (send_and_return_server(server, "524", 3, 3));
	ft_strcpy(server->buffer, "201 ");
	while ((s->len = read(s->fd, &(server->buffer[4]), SIZE_BUF - 4)) > 0)
	{
		printf("OK-TURN : %d\n", s->len + 4);
		send(server->sock, server->buffer, s->len + 4, 0);
		recv(server->sock, server->buffer, SIZE_BUF, 0);		
	}
	ft_putstr("FUCK OF\n");
	send(server->sock, "200", 3, 0);
	destroy_get_server(s);
	return (ret_and_close(s->fd, 3));
}
