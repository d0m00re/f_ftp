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

int				ft_get(t_server *server)
{
	int			ret;
	int			fd;
	size_t		len;

	if (good_param(server))
		return (3);
	server->len_header = ft_strlen(server->sp_buffer[0]) +\
	ft_strlen(server->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
	if ((fd = open(server->sp_buffer[1], O_RDONLY)) == -1)
	{
		ft_putstr("FUCK OGFFFFFFFFFFFFFFFFFf - file not found\n");
		return (send_and_return_server(server, "524", 3, 3));
	}
	while ((len = read(fd, &(server->buffer[server->len_header]),\
	SIZE_BUF - server->len_header)) > 0)
	{
		printf("Turn .... : %lu\n", len + server->len_header);
		if ((send(server->sock, server->buffer,\
		len + server->len_header, 0)) == -1)
			return (1);
		ret = recv(server->sock, server->buffer, SIZE_BUF, 0);
		concat_2dchar_in_buffer(server->buffer, server->sp_buffer, 2, " ");
		printf("Turnos ...\n");
	}
	ft_strcpy(server->buffer, "200");
	send(server->sock, server->buffer, 3, 0);
	return (ret_and_close(fd, 3));
}
