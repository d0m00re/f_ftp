/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:12:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:12:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "mtf_input.h"
#include "ft_string.h"
#include "server.h"
#include "ft_display.h"
#include "setting.h"
#include "client.h"

int			find_builtin(char *str)
{
	if (!ft_strcmp(str, "ls"))
		return (LS);
	else if (!ft_strcmp(str, "cd"))
		return (CD);
	else if (!ft_strcmp(str, "get"))
		return (GET);
	else if (!(ft_strcmp(str, "put")))
	{
		ft_putstr("put.\n");
		return (PUT);
	}
	else if (!ft_strcmp(str, "pwd"))
		return (PWD);
	else if (!ft_strcmp(str, "quit"))
		return (QUIT);
	else if (!ft_strcmp(str, "mkdir"))
		return (MKDIR);
	return (ERROR_CMD);
}

void		manual_add_info_client(t_client *client, char *msg)
{
	ft_strcpy(client->buffer, msg);
	client->size_buf = ft_strlen(msg);
}

void		init_main_client(t_client *client, int *num_builtin, int *ret)
{
	ft_bzero(client->buffer, SIZE_BUF);
	client->size_buf = 0;
	client->sp_buffer = ft_strsplit_free(client->sp_buffer);
	client->sp_buffer = ft_strsplit_nb_word(client->input, ' ',\
	&(client->size_sp));
	*num_builtin = find_builtin(client->sp_buffer[0]);
	*ret = 0;
}

int			end_main_client(t_client *client, int num_builtin)
{
	remaster_prompt(client->buffer, client->size_buf);
	return (num_builtin);
}

int			main_client(t_client *client)
{
	int		num_builtin;
	int		ret;

	init_main_client(client, &num_builtin, &ret);
	if (num_builtin == PUT && client->size_sp == 2)
	{
		if ((ret = manage_put_client(client)) == 0)
			client->size_buf = recv(client->sock, client->buffer, SIZE_BUF, 0);
	}
	else if (num_builtin == GET && client->size_sp == 2)
		ret = manage_get_client(client);
	else if (num_builtin == PWD && client->size_sp == 1)
		my_send_and_recv(client);
	else if (num_builtin == CD && (client->size_sp == 1 ||\
	client->size_sp == 2))
		my_send_and_recv(client);
	else if (num_builtin == LS && client->size_sp == 1)
		my_send_and_recv(client);
	else if (num_builtin == MKDIR && client->size_sp == 2)
		my_send_and_recv(client);
	else if (num_builtin == QUIT)
		return (700);
	else
		ft_usage_builtin_store(client, num_builtin);
	client->sp_buffer = ft_strsplit_free(client->sp_buffer);
	return (end_main_client(client, num_builtin));
}
