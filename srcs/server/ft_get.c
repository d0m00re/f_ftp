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
#include <stdlib.h>
#include <sys/socket.h>

static int		good_param(t_server *server)
{
	if (server->size_sp < 2)
		return (send_and_return(server, "521", 3, 3));
	if (check_futur_path(server) == 0)
		return (send_and_return(server, "522", 3, 3));
	if (is_file(server->sp_buffer[1]) == 0)
		return (send_and_return(server, "523", 3, 3));
	return (0);
}

int				ft_get(t_server *server)
{
	t_get_server *s;

	if (good_param(server))
		return (3);
	s = init_get_server(server);
	if ((s->fd = open(s->name_file, O_RDONLY)) == -1)
		return (send_and_return(server, "524", 3, 3));
	ft_strcpy(server->buffer, "201 ");
	while ((s->len = read(s->fd, &(server->buffer[4]), SIZE_BUF - 4)) > 0)
	{
		send(server->sock, server->buffer, s->len + 4, 0);
		recv(server->sock, server->buffer, SIZE_BUF, 0);
	}
	send(server->sock, "200", 3, 0);
	destroy_get_server(s);
	return (ret_and_close(s->fd, 3));
}
