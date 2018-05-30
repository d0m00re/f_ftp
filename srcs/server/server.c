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

#include "server.h"
#include "ft_string.h"
#include "ft_display.h"

static void usage(char *str)
{
        printf("Usage: %s <port>\n", str);
        exit(-1);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs; // socket client
	unsigned int		cslen;
	struct sockaddr_in 	csin;
	t_server_integ		*i;
	int r;
	char buf[1024];
	int ret_server = 0;
	int num_builtins = 0;

	if (ac != 2)
		usage(av[0]);
	i = server_integ_make("ft_ftp");
	/*
	** GESTION DU SERVEUR
	*/
        if (check_good_path(i))
        {

        }
	/*
	** CREATION DU REPERTOIRE SI IL N EXISTE PAS
	*/
        if (create_reper_server(i))
        {

        }
	port = atoi(av[1]);
	sock = create_server(port); //creation
	cs = accept(sock, (struct sockaddr*)&csin, &cslen);
	while (1)
	{
		main_server(cs, buf, r, i);
	}


	close(sock); //destruction
	return (1);
}
