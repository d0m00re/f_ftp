/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 04:27:40 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/06 04:28:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <stdio.h>
#include <sys/socket.h>
#include "setting.h"
#include <unistd.h>
#include <stdlib.h>

/*
** restrict name of file put by extratc last significative name of file
*/

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

static void	core_ft_put(t_server *server, char *last_sign, int *c)
{
	server->size_buf = recv(server->sock, server->buffer, SIZE_BUF, 0);
	if (server->size_buf > 3)
	{
		server->sp_buffer = ft_strsplit_nb_word(server->buffer, ' ',\
		&(server->size_sp));
		server->num_built = find_builtin(server->sp_buffer[0]);
		if (server->num_built == PUT && server->size_sp >= 2)
		{
			ft_file_write_end(last_sign,\
			&(server->buffer[(size_t)server->len_header]),\
			((size_t)server->size_buf - server->len_header));
		}
		else
			*c = 1;
	}
	else
	{
		ft_putstr("Other affectation ....\n");
		*c = 1;
	}
	send(server->sock, "200 ", 4, 0);
}

int			ft_put(t_server *server)
{
	int		c;
	char	*last_sign;

	c = 0;
	if (server->size_sp < 2)
		return (send_and_return(server, "777", 3, 3));
	if (!(last_sign = extract_last_signif(server->sp_buffer[1])))
		last_sign = server->sp_buffer[1];
	if (is_not_file_but_other(server->sp_buffer[1]))
		return (send_and_return(server, "532", 3, 1));
	last_sign = ft_strdup(last_sign);
	server->len_header = ft_strlen(server->sp_buffer[0]) +\
	ft_strlen(server->sp_buffer[1]) + 2;
	ft_file_write_begin(last_sign,\
	&(server->buffer[(size_t)server->len_header]),\
	(size_t)server->size_buf - server->len_header);
	if ((send(server->sock, "200 ", 4, 0)) == -1)
		return (ft_putstr_ret("ft_put : error send data to the client\n", 1));
	printf("c : %d\n", c);
	while (!c)
	{
		server->sp_buffer = ft_strsplit_free(server->sp_buffer);
		core_ft_put(server, last_sign, &c);
		server->sp_buffer = ft_strsplit_free(server->sp_buffer);
	}
	free(last_sign);
	ft_putstr("And valid ....\n");
	return (0);
}
