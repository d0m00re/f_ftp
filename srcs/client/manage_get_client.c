/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_get_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:19:22 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/07 04:26:57 by alhelson         ###   ########.fr       */
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
#include "server.h"

static char	*extract_last_signif(char *s)
{
	char	*str;

	if (!(str = ft_strrchr(s, '/')))
		return (ft_strdup(s));
	str++;
	if (!(str))
		return (0);
	return (ft_strdup(str));
}

typedef	struct s_get_client
{
	char *cmd;
	char *name_file;
	char *header;

	int len_cmd;
	int len_name;
	int len_header;

	char **sp_buffer;
	int sp_size;

	int real_size; // size of data
	int actual_turn;
} t_get_client;

t_get_client *init_get_client(t_client *client)
{
	t_get_client *gc;

	if (!(gc = malloc(sizeof(t_get_client))))
		return (0);
	if (!(gc->cmd = ft_strdup("get")))
		return (0);
	if (!(gc->name_file = extract_last_signif(client->sp_buffer[1])))
		return (0);
	gc->len_cmd = ft_strlen(gc->cmd);
	gc->len_name = ft_strlen(gc->name_file);
	gc->len_header = gc->len_cmd + gc->len_name + 2;
	ft_putstr("coucou\n");
	if (!(gc->header = malloc(sizeof(char) * (gc->len_header + 1))))
		return (0);
	printf("buffer : %s | %s\n", gc->name_file, gc->cmd);
	concat_2dchar_in_buffer(gc->header, client->sp_buffer, 2, " ");
	gc->actual_turn = 0;
	printf("cmd --> %s\n", gc->cmd);
	printf("name_file --> %s\n", gc->name_file);
	printf("header --> %s\n", gc->header);
	return (gc);
}

void	destroy_get_client(t_get_client *gc)
{
	free(gc->cmd);
	free(gc->name_file);
	free(gc->header);
	free(gc);
}

int	get_send_recv(t_client *client, t_get_client *cg)
{
	send(client->sock, cg->header, cg->len_header, 0);
	client->size_buf = recv(client->sock, client->buffer, SIZE_BUF, 0);
	return (1);
}

/*
** restriction repertoire courant
*/
int manage_get_client(t_client *client)
{
	t_get_client *cg;

	cg = init_get_client(client);
	client->size_buf = 666;
	while (client->size_buf != 3) // fin == 3
	{
		printf("Turn .... : %d\n", client->size_buf);
		get_send_recv(client, cg);
		ft_write_file(cg->name_file, &(client->buffer[4]), client->size_buf - 4, cg->actual_turn);
		cg->actual_turn += 1;
	}
	printf("nb turn : %d\n", cg->actual_turn);
	destroy_get_client(cg);
	return (1);
}
