/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:52:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/03 06:52:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "server.h"
#include "ft_string.h"
#include "setting.h"
#include "client.h"

void	ft_usage_builtin(int num)
{
	if (num == PUT)
		ft_putstr(USAGE_PUT);
	else if (num == GET)
		ft_putstr(USAGE_GET);
	else if (num == PWD)
		ft_putstr(USAGE_PWD);
	else if (num == CD)
		ft_putstr(USAGE_CD);
	else if (num == MKDIR)
		ft_putstr(USAGE_MKDIR);
	else if (num == LS)
		ft_putstr(USAGE_LS);
	else
		ft_putstr(USAGE_BUILTIN);
}

void	ft_usage_builtin_store(t_client *client, int num)
{
	ft_strcpy(client->buffer, "666 ");
	if (num == PUT)
		ft_strcat(client->buffer, USAGE_PUT);
        else if (num == GET)
                ft_strcat(client->buffer, USAGE_GET);
        else if (num == PWD)
                ft_strcat(client->buffer, USAGE_PWD);
        else if (num == CD)
                ft_strcat(client->buffer, USAGE_CD);
        else if (num == MKDIR)
                ft_strcat(client->buffer, USAGE_MKDIR);
        else if (num == LS)
                ft_strcat(client->buffer, USAGE_LS);
        else
                ft_strcat(client->buffer, USAGE_BUILTIN);
	client->size_buf = ft_strlen(client->buffer);
}
