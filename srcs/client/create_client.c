/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:51:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/03 06:51:55 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "mtf_input.h"
#include "ft_string.h"

#include "server.h"
#include "client.h"

#include "ft_display.h"

int						create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if ((sock = socket(PF_INET, SOCK_STREAM,\
					proto->p_proto)) == -1)
	{
		ft_putstr("* socket creation error.\n");
		return (-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if ((connect(sock, (const struct sockaddr *)&sin,\
					sizeof(sin))) == -1)
	{
		ft_putstr("* connect error\n");
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}
