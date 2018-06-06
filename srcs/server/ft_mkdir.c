/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:20:50 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 08:20:58 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "server.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include "setting.h"
#include <sys/socket.h>
#include "ft_string.h"

int	ft_mkdir(t_server *server)
{
	if ((mkdir(server->sp_buffer[1], 0777)) == -1)
		ft_strcpy(server->buffer, ERROR_MKDIR);
	else
		ft_strcpy(server->buffer, SUCCESS_CMD);
	send(server->sock, server->buffer, 3, 0);
	return (0);
}
