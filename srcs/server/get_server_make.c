/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server_make.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:55:08 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/07 18:58:32 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_string.h"
#include <stdlib.h>

t_get_server		*init_get_server(t_server *server)
{
	t_get_server	*gs;

	if (!(gs = malloc(sizeof(t_get_server))))
		return (0);
	if (!(gs->cmd = ft_strdup("get")))
		return (0);
	if (!(gs->name_file = ft_strdup(server->sp_buffer[1])))
		return (0);
	gs->len_cmd = ft_strlen(gs->cmd);
	gs->len_name = ft_strlen(gs->name_file);
	if (!(gs->header = malloc(sizeof(char) * (gs->len_cmd + gs->len_name + 3))))
		return (0);
	concat_2dchar_in_buffer(gs->header, server->sp_buffer, 2, " ");
	gs->len_header = ft_strlen(gs->header);
	gs->sp_buffer = 0;
	gs->sp_size = 0;
	gs->real_size = 0;
	gs->fd = 0;
	return (gs);
}

void				destroy_get_server(t_get_server *s)
{
	free(s->cmd);
	free(s->name_file);
	free(s->header);
	free(s);
}
