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

int                                             create_server(int port)
{
	int			sock;
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
