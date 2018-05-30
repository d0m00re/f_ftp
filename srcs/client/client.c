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

void    usage(char *str)
{
        printf("Usage: %s <addr> <port>\n", str);
        exit(-1);
}

int						main(int ac, char **av)
{
	char *input;
	int					port;
	int					sock;
	char buf[1024];

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port); //creation
	int rett;
	int size_recv;
	//write(sock, "Ma bite\n", 8);
	while (1)
	{
		input = main_input();
		main_client(sock, input, buf);
	}

	close(sock); //destruction
	return (1);
}
