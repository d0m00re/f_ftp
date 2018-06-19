/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_send_and_recv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:07:02 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:08:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_string.h"
#include "setting.h"
#include <sys/socket.h>
#include "ft_display.h"
#include <stdio.h>

int		my_send_and_recv(t_client *client)
{
	int	ret;

	ret = 0;
	if ((send(client->sock, client->input, ft_strlen(client->input), 0)) == -1)
		ret = 1;
	if (ret == 0 && (client->size_buf = recv(client->sock,\
	client->buffer, SIZE_BUF, 0)) == -1)
		ret = 1;
	if (ret)
	{
		ft_strcpy(client->buffer, "700");
		client->size_buf = 3;
	}
	return (ret);
}

int		update_client_and_ret(t_client *client, char *s, int ret)
{
	ft_strcpy(client->buffer, s);
	client->size_buf = ft_strlen(client->buffer);
	return (ret);
}
