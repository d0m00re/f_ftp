/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 06:13:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/18 04:33:00 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "ft_string.h"
#include "ft_file.h"
#include <sys/socket.h>
#include <stdlib.h>
#include "ft_display.h"
#include <unistd.h>

int				send_and_return(t_server *server, char *str, int len, int ret)
{
	send(server->sock, str, len, 0);
	return (ret);
}

int				check_futur_path(t_server *s)
{
	char		*path_to_test;
	char		*path;
	size_t		size;
	int			valid_path;

	if (!(path = ft_strextract_before_rchr(s->sp_buffer[1], '/')))
		return (1);
	size = ft_strlen(path) + ft_strlen(s->actual);
	if (!(path_to_test = malloc(sizeof(char) * (size + 2))))
	{
		free(path);
		return (0);
	}
	ft_strcpy(path_to_test, s->actual);
	ft_strcat(path_to_test, "/");
	ft_strcat(path_to_test, path);
	valid_path = valid_path_no_dess(s->full, path_to_test);
	free(path_to_test);
	free(path);
	return (valid_path);
}

int				check_futur_path2(t_server *s)
{
	char		actual_path[2048];
	char		futur_path[2048];
	int			valid_path;

	if (!getcwd(actual_path, 2048))
		return (0);
	if (chdir(s->sp_buffer[1]))
		return (0);
	if (!getcwd(futur_path, 2048))
	{
		chdir(actual_path);
		return (0);
	}
	valid_path = valid_path_no_dess(s->full, futur_path);
	chdir(actual_path);
	return (valid_path);
}
