/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 00:37:59 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/28 00:38:37 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tcp ip : chacun a une ip et le port pour parler a un service en particulier
// 12.33.56.7 : 80

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h> // /usr/include/netinet/in.h
#include <sys/wait.h>

#include "server.h"
#include "ft_string.h"
#include "ft_display.h"

static void usage(char *str)
{
        printf("Usage: %s <port>\n", str);
        exit(-1);
}

int	main(int ac, char **av)
{
	t_server *server;
	int port;
	int sock;
	unsigned int		cslen;
	struct sockaddr_in 	csin;
	pid_t pid;
	int res_fils;

	if (ac != 2)
		usage(av[0]);
        port = atoi(av[1]);
        sock = create_server(port);
	if (!(server = server_make("beatiful_server")))
	{
		ft_putstr("Error creation server.\n");
		return (1);
	}
	while (1)
	{
		server->sock = accept(sock, (struct sockaddr*)&csin, &cslen);
		if ((pid = fork()) == -1)
		{
			close(server->sock);
			continue;
		}
		else if (pid == 0)
		{
			while (1)
			{
				ft_bzero(server->buffer, 1024);
				main_server(server);
			}
			close(server->sock);
			break;
		}
		else if (pid > 0)
		{
			close(server->sock);
		}
	}
}
