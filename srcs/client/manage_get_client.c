/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_get_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:19:22 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 04:05:45 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_file.h"
#include <string.h>
#include <stdio.h>
#include "ft_string.h"
#include <stdlib.h>
#include <sys/socket.h>
#include "setting.h"
#include "ft_display.h"
#include "server.h"
#include <string.h>
#include "client.h"

static char	*extract_last_signif(char *s)
{
	char	*str;

	if (!(str = ft_strrchr(s, '/')))
		return (s);
	str++;
	if (!(str))
		return (0);
	return (str);
}

int			initalize_get_client(t_client *client,\
char **last_sign, char **old_string, int *c)
{
	int		len_header;

	if (client->size_sp < 2)
		return (update_client_and_ret(client, "856 : invalid nb argument", 0));
	if (!(*last_sign = extract_last_signif(client->sp_buffer[1])))
		*last_sign = client->sp_buffer[1];
	*c = 0;
	len_header = ft_strlen(client->sp_buffer[0]) +\
	ft_strlen(client->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	*old_string = ft_strdup(client->buffer);
	send(client->sock, client->buffer, 1024, 0);
	client->size_buf = recv(client->sock, client->buffer, 1024, 0);
	if (client->size_buf == 3 && ft_strcmp(client->buffer, "714") == 0)
		return (0);
	ft_file_write_begin(*last_sign, &(client->buffer[(size_t)len_header]),\
	(size_t)client->size_buf - len_header);
	send(client->sock, *old_string, ft_strlen(*old_string), 0);
	return (len_header);
}

int			core_manage_get_client(t_client *client,\
int len_header, char *old_string, char *last_sign)
{
	if ((client->size_buf = recv(client->sock,\
	client->buffer, SIZE_BUF, 0)) > 3)
	{
		client->sp_buffer = ft_strsplit_nb_word(client->buffer,\
		' ', &(client->size_sp));
		if (find_builtin(client->sp_buffer[0]) == GET && client->size_sp >= 2)
			ft_file_write_end(last_sign, &(client->buffer[(size_t)len_header]),\
			((size_t)client->size_buf - len_header));
		else
			return (ft_putstr_ret("Error get client.\n", 0));
		send(client->sock, old_string, ft_strlen(old_string), 0);
	}
	else
		return (-1);
	return (1);
}

/*
** dans le cas ou on a un taille de 3 c est ok
** c -= 1 nous permet das le cas ou on renvoi -1 de
** finir la boucle car == -2 in this is other case
*/

int			manage_get_client(t_client *client)
{
	char	*old_string;
	int		c;
	size_t	len_header;
	char	*last_sign;

	len_header = 0;
	old_string = 0;
	last_sign = 0;
	if ((len_header = initalize_get_client(client,\
	&last_sign, &old_string, &c)) == 0)
		return (0);
	while (!c)
	{
		if ((c = core_manage_get_client(client, len_header,\
		old_string, last_sign)) == 0)
			return (0);
		c -= 1;
	}
	return (client->size_buf);
}
