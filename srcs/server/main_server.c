/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:07:06 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 06:07:29 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <sys/socket.h>
#include "setting.h"
#include <stdlib.h>
#include "ft_string.h"

void	core_main_server(t_server *server)
{
	if (server->num_built)
	{
		if (server->num_built == PUT)
			ft_put(server);
		else if (server->num_built == GET && server->size_sp == 2)
			ft_get(server);
		else if (server->num_built == PWD)
			ft_pwd(server);
		else if (server->num_built == CD)
			ft_cd(server);
		else if (server->num_built == LS)
			ft_ls(server);
		else if (server->num_built == QUIT)
		{
			ft_quit(server);
			close(server->sock);
		}
		else if (server->num_built == MKDIR)
			ft_mkdir(server);
		else
			send(server->sock, "500", 3, 0);
	}
	else
		send(server->sock, "500", 3, 0);
}

char	*main_server(t_server *server)
{
	if ((server->size_buf = recv(server->sock,\
	server->buffer, SIZE_BUF, 0)) == -1)
	{
		server->running = 0;
		return (0);
	}
	server->num_built_old = server->num_built;
	server->sp_buffer = ft_strsplit_free(server->sp_buffer);
	server->sp_buffer = ft_strsplit_nb_word(server->buffer,\
	' ', &(server->size_sp));
	server->num_built = find_builtin(server->sp_buffer[0]);
	core_main_server(server);
	server->sp_buffer = ft_strsplit_free(server->sp_buffer);
	return (0);
}
