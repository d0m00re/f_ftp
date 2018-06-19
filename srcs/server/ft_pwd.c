/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 05:52:04 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 05:52:12 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_file.h"
#include "server.h"
#include "ft_string.h"
#include <sys/socket.h>
#include <stdlib.h>

int			ft_pwd(t_server *server)
{
	char	*new;

	new = extract_string_diff(server->full, server->actual);
	if (!new)
		new = ft_strdup("/");
	ft_strcpy(server->buffer, "200 ");
	ft_strcat(server->buffer, new);
	send(server->sock, server->buffer, ft_strlen(server->buffer), 0);
	free(new);
	return (0);
}
