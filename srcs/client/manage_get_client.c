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
#include <string.h>
#include "client.h"


/*
** dans le cas ou on a un taille de 3 c est ok
*/

int manage_get_client(t_client *client)
{
	char *old_string;
	int c;
	size_t len_header;

	if (client->size_sp < 2)
		exit(1);
	c = 0;
	len_header = ft_strlen(client->sp_buffer[0]) + ft_strlen(client->sp_buffer[1]) + 2;
	concat_2dchar_in_buffer(client->buffer, client->sp_buffer, 2, " ");
	old_string = ft_strdup(client->buffer);
	send(client->sock, client->buffer, 1024, 0);
	client->size_buf = recv(client->sock, client->buffer, 1024, 0);
	if (client->size_buf == 3 && ft_strcmp(client->buffer, "714") == 0)
	{
		return (0);
	}
	ft_file_write_begin(client->sp_buffer[1], &(client->buffer[(size_t)len_header]), (size_t)client->size_buf - len_header);
	send(client->sock, old_string, ft_strlen(old_string), 0);
	while (!c)
	{
		if ((client->size_buf = recv(client->sock, client->buffer, SIZE_BUF, 0)) > 3)
		{
			client->sp_buffer = ft_strsplit_nb_word(client->buffer, ' ', &(client->size_sp));
			if (find_builtin(client->sp_buffer[0]) == GET && client->size_sp >= 2)
				ft_file_write_end(client->sp_buffer[1], &(client->buffer[(size_t)len_header]), ((size_t)client->size_buf - len_header));
			else
			{
				ft_putstr("Error get client.\n");
				return (0);
			}
			send(client->sock, old_string, ft_strlen(old_string), 0);
		}
		else
			c = 1;
	}
	return (client->size_buf);
}
