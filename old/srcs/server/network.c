/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:13:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 06:15:00 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/socket.h>

int	send_and_return(t_server *server, char *str, int len, int ret)
{
	send(server->sock, str, len, 0);
	return (ret);
}
