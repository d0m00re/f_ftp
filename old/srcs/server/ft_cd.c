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
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "ft_file.h"

/*
** moove in rep specified
** modification of localisation variable
*/

static int	check_futur_path(t_server *s)
{
	int		valid_path;
	size_t	size;
	char	*futur_full_path;

	size = ft_strlen(s->actual);
	size += ft_strlen(s->sp_buffer[1]);
	if (!(futur_full_path = malloc(sizeof(char) * (size + 2))))
		return (0);
	ft_strcpy(futur_full_path, s->actual);
	ft_strcat(futur_full_path, "/");
	ft_strcat(futur_full_path, s->sp_buffer[1]);
	valid_path = valid_path_no_dess(s->full, futur_full_path);
	free(futur_full_path);
	return (valid_path);
}

int			ft_cd(t_server *server)
{
	if (server->size_sp != 2)
		ft_strcpy(server->buffer, "510");
	else if (check_futur_path(server) == 0)
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
