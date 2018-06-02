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

#include "mtf_input.h"
#include "ft_string.h"

#include "server.h"
#include "client.h"

#include "ft_display.h"

#include <signal.h>

void    usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <addr> <port>\n");
        exit(-1);
}

int						main(int ac, char **av)
{
	char *input;
	int					port;
	int					sock;
	char buf[1024];
	int rett;
	int size_recv;

	if (ac != 3)
		usage(av[0]);
	if ((port = atoi(av[2])) < 1)
	{
		ft_putstr("server : wrong port.\n");
		return (1);
	}
	if ((sock = create_client(av[1], port)) == -1) //creation
		return (1);
	rett = 0;
	// initalisation du signal
	signal(SIGINT, true_sigint);
	while (rett != 700 && !(get_sigint()))
	{
		input = main_input();
		if (get_sigint())
			ft_strcpy(input, "quit");
		rett = main_client(sock, input, buf);
	}
	close(sock);
	return (0);
}
