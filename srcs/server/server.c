/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 00:37:59 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 04:47:25 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** tcp ip : chacun a une ip et le port pour parler a un service en particulier
** 12.33.56.7 : 80
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

#include "server.h"
#include "ft_string.h"
#include "ft_display.h"

static int				usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
	return (0);
}

static void				core_server(t_server *server)
{
	while (server->running)
	{
		ft_bzero(server->buffer, 1024);
		main_server(server);
	}
	close(server->sock);
}

static t_server			*initialize_server(int ac, char **av, int *sock)
{
	t_server *server;

	if (ac != 2)
	{
		usage(av[0]);
		return (0);
	}
	*sock = atoi(av[1]);
	*sock = create_server(*sock);
	if (!(server = server_make("beatiful_server")))
	{
		ft_putstr("Error creation server.\n");
		return (0);
	}
	return (server);
}

int						main(int ac, char **av)
{
	t_server			*server;
	int					sock;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				pid;

	if ((server = initialize_server(ac, av, &sock)) == 0)
		return (0);
	while (server->running)
	{
		if ((server->sock = accept(sock,\
		(struct sockaddr*)&csin, &cslen)) == -1)
			return (1);
		if ((pid = fork()) == -1)
		{
			close(server->sock);
			continue;
		}
		else if (pid == 0)
			core_server(server);
		else if (pid > 0)
			close(server->sock);
	}
	close(sock);
}
