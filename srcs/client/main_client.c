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
#include "ft_display.h"
#include "setting.h"
#include "client.h"

int find_builtin(char *str)
{
        if (!ft_strcmp(str, "ls"))
                return (LS);
        else if (!ft_strcmp(str, "cd"))
                return (CD);
        else if (!ft_strcmp(str, "get"))
                return (GET);
        else if (!(ft_strcmp(str, "put")))
                return (PUT);
        else if (!ft_strcmp(str, "pwd"))
                return (PWD);
        else if (!ft_strcmp(str, "quit"))
                return (QUIT);
        return (ERROR_CMD);
}

int main_client(int sock, char *input, char buffer[1024])
{
	char **strsp; // split of input
	int nb_word;
	int num_builtin;
	int ret;

	strsp = ft_strsplit_nb_word(input, ' ', &nb_word);
	num_builtin = find_builtin(strsp[0]);

	if (num_builtin == PUT)
	{
		ft_putstr("PUT.\n");
		manage_put_client(sock, strsp, buffer);
	}
	else if (num_builtin) // dans le cas ou c est une builtin valide, pas encore de check de validite de synthaxe
	{
		ft_putstr("NUM BUILTIN\n");
		send(sock, input, ft_strlen(input), 0);
		ret = recv(sock, buffer,SIZE_BUF,0);
	}
	else
	{
		ft_putstr("Wrong builting\n");
		return (0);
	}
	return (1);
}
