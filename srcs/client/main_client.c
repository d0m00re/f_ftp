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
	else if (!ft_strcmp(str, "mkdir"))
		return (MKDIR);
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
	if (num_builtin == PUT && nb_word == 2)
	{
		manage_put_client(sock, strsp, buffer);
                ret = recv(sock, buffer, 1024, 0);
                ft_putstr_limit(buffer, ret);
	}
	else if (num_builtin == GET && nb_word == 2)
	{
		manage_get_client(sock, strsp, buffer, ft_strlen(buffer), nb_word);
		ret = recv(sock, buffer, 1024, 0);
		ft_putstr_limit(buffer, ret);
	}
	else if (num_builtin == PWD && nb_word == 1)
	{
		send(sock, "pwd", 3, 0);
		ret = recv(sock, buffer, 1024, 0);
		//ft_putstr_limit(buffer, ret);
	}
        else if (num_builtin == CD && (nb_word == 1 || nb_word == 2))
        {
                send(sock, input, ft_strlen(input), 0);
                ret = recv(sock, buffer, 1024, 0);
                //ft_putstr_limit(buffer, ret);
        }
	else if (num_builtin == LS && nb_word == 1)
	{
		//ft_putstr("LS:\n");
		send(sock, input, ft_strlen(input), 0);
		ret = recv(sock, buffer, 1024, 0);
		//ft_putstr_limit(buffer, ret);
	}
	else if (num_builtin == MKDIR && nb_word == 2)
	{
		send(sock, input, ft_strlen(input), 0);
		ret = recv(sock, buffer, 1024, 0);
		//ft_putstr_limit(buffer, ret);
	}
	else if (num_builtin == QUIT && nb_word == 1)
	{
		//printf("---> %s|%zu", input, ft_strlen(input));
		send(sock, input, ft_strlen(input), 0);
		ret = recv(sock, buffer, 1024, 0);
	}
	else
		ft_usage_builtin(num_builtin);
	ft_putchar('\n');
	ft_putstr_limit(buffer, 3);	
	if (ret == 3 && ft_strcmp(buffer, "700") == 0)
		return (700);
	return (num_builtin);
}
