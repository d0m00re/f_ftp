/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 00:37:59 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:00:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** tcp ip : chacun a une ip et le port pour parler a un service en particulier
** 12.33.56.7 : 80
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "mtf_input.h"
#include "ft_string.h"
#include "ft_stdlib.h"
#include "server.h"
#include "client.h"
#include "ft_display.h"

int					usage(char *str)
{
	ft_putstr(" Usage: ");
	ft_putstr(str);
	ft_putstr(" <addr> <port>\n");
	return (-1);
}

int					main_create_client(t_client *client,\
					char *addr, int port)
{
	if (ft_strcmp(addr, "localhost") == 0)
	{
		if ((client->sock = create_client("127.0.0.1", port)) == -1)
			return (1);
	}
	else if ((client->sock = create_client(addr, port)) == -1)
		return (1);
	return (0);
}

int					main(int ac, char **av)
{
	int				port;
	int				ret;
	t_client		*client;

	if (ac != 3)
		return (usage(av[0]));
	if ((port = ft_atoi(av[2])) < 1)
		return (ft_putstr_ret("wrong port.\n", 1));
	client = make_client();
	if (main_create_client(client, av[1], port))
		return (1);
	ret = 0;
	while (ret != 700)
	{
		if (!(client->input = main_input()))
			ret = 700;
		else if (ft_strlen(client->input) > 0)
		{
			client->size_input = ft_strlen(client->input);
			ret = main_client(client);
		}
		free(client->input);
	}
	close(client->sock);
	return (0);
}
