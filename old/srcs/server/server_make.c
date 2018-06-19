/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:50:43 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:51:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ft_display.h"

static int			ft_create_rep_if_no_exist(char *server_name)
{
	struct stat		sb;

	ft_putstr("*creation server : ");
	ft_putstr(server_name);
	ft_putchar('\n');
	if (stat(server_name, &sb) != -1)
		return (1);
	if (mkdir(server_name, 0777) == -1)
		return (1);
	return (1);
}

t_server			*server_make(char *server_name)
{
	t_server		*server;

	if (!(server = malloc(sizeof(t_server))))
		return (0);
	server->deph = 0;
	server->name = strdup(server_name);
	server->sp_buffer = 0;
	server->valid_ftp = 0;
	server->valid_path = 1;
	server->rep_is_create = ft_create_rep_if_no_exist(server_name);
	chdir(server_name);
	server->full = getcwd(malloc(1024), 1024);
	server->actual = strdup(server->full);
	server->valid_ftp = 1;
	server->rep_is_create = 1;
	server->running = 1;
	return (server);
}

void	server_make2(t_server *server, char *server_name)
{
        if (!(server = malloc(sizeof(t_server))))
                return ;
        server->deph = 0;
        server->name = strdup(server_name);
        server->sp_buffer = 0;
        server->valid_ftp = 0;
        server->valid_path = 1;
        server->rep_is_create = ft_create_rep_if_no_exist(server_name);
        chdir(server_name);
        server->full = getcwd(malloc(1024), 1024);
        server->actual = strdup(server->full);
        server->valid_ftp = 1;
        server->rep_is_create = 1;
        server->running = 1;
}
