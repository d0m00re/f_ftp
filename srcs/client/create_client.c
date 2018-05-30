#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h> // /usr/include/netinet/in.h

#include "mtf_input.h"
#include "ft_string.h"

#include "server.h"
#include "client.h"

int	create_client(char *addr, int port)
{
	int                                     sock;
	struct protoent         *proto; // get numero of protocol
	struct sockaddr_in      sin;

	proto = getprotobyname("tcp");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;//famille d adresse
	sin.sin_port = htons(port); // on doit fair en sorte d adapter le type d endianess
	sin.sin_addr.s_addr = inet_addr(addr);//adresse - convertir une chaine de catacrete en addr
	connect(sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(sock, 42); //taille de la queu qui nous permet de recevoir la connexion
	return (sock);
}
