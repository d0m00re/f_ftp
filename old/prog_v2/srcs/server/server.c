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

void usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int						create_server(int port)
{
	int					sock;
	struct protoent		*proto; // get numero of protocol
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	printf("proto : %d\n", proto->p_proto);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		printf("Socket error\n");
		exit(1);
	}
	sin.sin_family = AF_INET;//famille d adresse
	sin.sin_port = htons(port); // on doit fair en sorte d adapter le type d endianess
			// pour cela on va utiliser des macro
	sin.sin_addr.s_addr = htonl(INADDR_ANY);//adresse
	if ((bind(sock, (const struct sockaddr *)&sin, sizeof(sin)))== -1)
	{
		printf("Bind error ...\n");
		exit(1);
	}
	listen(sock, 42); //taille de la queu qui nous permet de recevoir la connexion
	return (sock);
}

int						server_bitch(char buffer[1024], int r)
{
	char **split_arg;
	int nb_arg;
	int ret_type_cmd;

	split_arg = 0;
	buffer[r] = '\0';
	split_arg = ft_strsplit_nb_word(buffer, ' ', &nb_arg); //free le split
	ret_type_cmd = find_builtin(split_arg[0]);
	return (ret_type_cmd);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs; // socket client
	unsigned int		cslen;
	struct sockaddr_in 	csin;

	int r;
	char buf[1024];

	int ret_server = 0;

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port); //creation

	cs = accept(sock, (struct sockaddr*)&csin, &cslen);

	while ((r = read(cs, buf, 1023)) > 0)// && ret_server == QUIT)
	{
		if (r > 0)
		{
			ret_server = server_bitch(buf, r);

			//pour le moment on va etre naif mais faudrait attendre d avoir trouve le caractere de fin
			//write(cs, "END OF YOUR LIFE\n", 17);

			buf[r] = '\0';
			//printf("---> %s\n", buf);
			//printf("receiver %d bytes: [%s]\n", r, buf);
			find_builtin(buf);
			//printf("....\n");
		}
	}
	close(sock); //destruction
	return (1);
}
