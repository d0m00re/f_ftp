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

int	create_client(char *addr, int port)
{
	int                                     sock;
	struct protoent         *proto;
	struct sockaddr_in      sin;

	proto = getprotobyname("tcp");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		ft_putstr("* socket creation error.\n");
		return (-1);
	}
	sin.sin_family = AF_INET;//famille d adresse
	sin.sin_port = htons(port); // on doit fair en sorte d adapter le type d endianess
	sin.sin_addr.s_addr = inet_addr(addr);//adresse - convertir une chaine de catacrete en addr
	if ((connect(sock, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
	{
		ft_putstr("* connect error\n");
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}
