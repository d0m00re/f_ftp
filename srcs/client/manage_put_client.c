/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_put_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:53:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/03 23:04:39 by alhelson         ###   ########.fr       */
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

static int	get_size_header(char **sp_buffer)
{
	return (ft_strlen(sp_buffer[0]) +\
	ft_strlen(sp_buffer[1]) + 2);
}

static int	ret_and_close(int fd, int ret)
{
	close(fd);
	return (ret);
}

int			manage_put_client(t_client *client)
{
	size_t	len;
	int		fd;
	int		size_header;
	int		ret;

	ret = 0;
	if (is_file(client->sp_buffer[1]) == 0)
	{
		ft_strcpy(client->buffer, "889 : error is not a file");
		client->size_buf = ft_strlen(client->buffer);
		return (1);
	}
	if ((fd = open(client->sp_buffer[1], O_RDONLY)) == -1)
	{
		ft_strcpy(client->buffer, "888 : error open file.");
		client->size_buf = ft_strlen(client->buffer);
		return (1);
	}
	size_header = get_size_header(client->sp_buffer);
	concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	while ((len = read(fd, &(client->buffer[size_header]),\
					SIZE_BUF - size_header)) > 0)
	{
		if ((send(client->sock, client->buffer, len + size_header, 0)) == -1)
			return (ft_putstr_ret("put : error send data\n", 1));
		if ((ret = recv(client->sock, client->buffer, SIZE_BUF, 0)) == -1)
			return (ft_putstr_ret("put ; error recv data\n", 1));
		concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	}
	if ((send(client->sock, "put", 3, 0)) == -1)
		return (ft_putstr_ret("put : error last message\n", 1));
	printf("End return 0 ....\n");
	return (ret_and_close(fd, 0));
}
