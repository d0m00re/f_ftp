/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_put_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:53:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/03 06:53:50 by alhelson         ###   ########.fr       */
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

int			manage_put_client(t_client *client)
{
	size_t	len;
	int		fd;
	int		size_header;
	int		ret;

	if ((fd = open(client->sp_buffer[1], O_RDONLY)) == -1)
	{
		//ft_putstr("manage_put_client : error open file.\n");
		ft_strcpy(client->buffer, "888 manage_put_client : error open file.");
		return (ft_strlen(client->buffer));
	}
	size_header = ft_strlen(client->sp_buffer[0]) +\
	ft_strlen(client->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(client->buffer,\
	client->sp_buffer, 2, " ");
	while ((len = read(fd, &(client->buffer[size_header]),\
	SIZE_BUF - size_header)) > 0)
	{
		if ((send(client->sock, client->buffer,\
		len + size_header, 0)) == -1)
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		if ((ret = recv(client->sock, client->buffer,\
		SIZE_BUF, 0)) == -1)
		{
			ft_putstr("put ; error recv data\n");
			exit(1);
		}
		concat_2dchar_in_buffer(client->buffer,\
		client->sp_buffer, 2, " ");
	}
	ft_strcpy(client->buffer, "put");
	if ((send(client->sock, client->buffer, 3, 0)) == -1)
		ft_putstr("put : error send last message\n");
	close(fd);
	return (0);
}
