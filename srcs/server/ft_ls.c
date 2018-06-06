/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 00:03:47 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/04 00:04:19 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "ft_file.h"
#include <stdlib.h>
#include <stdio.h>

int			ft_ls(t_server *server)
{
	int		len;
	char	*buffer;

	len = 0;
	ft_putstr("\tSERVER : LS BEGIN\n");
	if (!(buffer = get_rep_string(".", &len)))
	{
		ft_putstr("* bad ls\n");
		ft_strcpy(server->buffer, "500");
		server->size_buf = 3;
	}
	else
	{
		printf("* good ls : %d\n", len);
		ft_strcpy(server->buffer, "200 ");
		ft_strcat(server->buffer, buffer);
		server->size_buf = len + 4;
		free(buffer);
	}
	send(server->sock, server->buffer, server->size_buf, 0);
	ft_putstr("\nSERVER : LS END\n");
	return (0);
}
