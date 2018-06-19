/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:07:57 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:31:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "ft_file.h"

int			ft_cd(t_server *server)
{
	if (server->size_sp != 2)
		ft_strcpy(server->buffer, "510");
	else if (check_futur_path2(server) == 0)
		ft_strcpy(server->buffer, "511");
	else if ((chdir(server->sp_buffer[1])) == -1)
		ft_strcpy(server->buffer, "511");
	else
	{
		if (server->actual)
			free(server->actual);
		if (!(server->actual = getcwd(malloc(1024), 1024)))
			ft_strcpy(server->buffer, "515");
		else
			ft_strcpy(server->buffer, "200");
	}
	send(server->sock, server->buffer, 3, 0);
	return (0);
}
