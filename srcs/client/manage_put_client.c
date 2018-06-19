/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_put_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:53:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 23:53:42 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "ft_file.h"
#include <string.h>
#include "ft_string.h"
#include <stdlib.h>
#include <sys/socket.h>
#include "setting.h"
#include "ft_display.h"

static int		get_size_header(char **sp_buffer)
{
	return (ft_strlen(sp_buffer[0]) +\
	ft_strlen(sp_buffer[1]) + 2);
}

static int		set_size_buff_and_return(t_client *client, int s, int ret)
{
	client->size_buf = s;
	return (ret);
}

int				manage_put_client(t_client *client)
{
	size_t		len;
	int			fd;
	int			lenh;
	int			ret;

	ret = 0;
	if (is_file(client->sp_buffer[1]) == 0)
		return (update_client_and_ret(client, "889 : error is not a file", 1));
	if ((fd = open(client->sp_buffer[1], O_RDONLY)) == -1)
		return (update_client_and_ret(client, "888 : error open file.", 1));
	lenh = get_size_header(client->sp_buffer);
	concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	while ((len = read(fd, &(client->buffer[lenh]), SIZE_BUF - lenh)) > 0)
	{
		if ((send(client->sock, client->buffer, len + lenh, 0)) == -1)
			return (ft_putstr_ret("put : error send data\n", 1));
		if ((ret = recv(client->sock, client->buffer, SIZE_BUF, 0)) == -1)
			return (ft_putstr_ret("put : error recv data\n", 1));
		if (ret == 3)
			return (set_size_buff_and_return(client, 3, 1));
		concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	}
	if ((send(client->sock, "put", 3, 0)) == -1)
		return (ft_putstr_ret("put : error last message\n", 1));
	return (ret_and_close(fd, 0));
}
