/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 02:36:27 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 02:36:38 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "setting.h"

int	ft_quit(t_server *server)
{
	server->running = 0;
	ft_strcpy(server->buffer, END_CLIENT);
	send(server->sock, server->buffer, 3, 0);
	return (1);
}
