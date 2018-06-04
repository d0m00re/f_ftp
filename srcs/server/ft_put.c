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

char *extract_last_signif(char *s)
{
	char *str;

	if (!(str = ft_strrchr(s, '/')))
		return (s);
	str++;
	if (!(str))
		return (0);
	return (str);
}

int ft_put(t_server *server)
{
	int c;
	char *last_sign;

	c = 0;
	last_sign = extract_last_signif(server->sp_buffer[1]);
	printf("---> %s\n", last_sign);
	server->len_header = ft_strlen(server->sp_buffer[0]) + ft_strlen(server->sp_buffer[1]) + 2;
	ft_file_write_begin(last_sign, &(server->buffer[(size_t)server->len_header]), (size_t)server->size_buf - server->len_header);
	if ((send(server->sock, "200", 3, 0)) == -1)
	{
		ft_putstr("ft_put : error send data to the client\n");
		return (1);
	}
	while (!c)
	{
		server->size_buf = recv(server->sock, server->buffer, SIZE_BUF, 0); // case where we write in the thile
		if (server->size_buf > 3) 
		{
			server->sp_buffer = ft_strsplit_nb_word(server->buffer, ' ', &(server->size_sp));
			server->num_built = find_builtin(server->sp_buffer[0]);
			if (server->num_built == PUT && server->size_sp >= 2)
				ft_file_write_end(last_sign, &(server->buffer[(size_t)server->len_header]), ((size_t)server->size_buf - server->len_header));
			else
			{
				printf("Error put : num built : %d | %s | %d | %d\n", server->num_built, server->sp_buffer[0], server->size_sp, server->size_buf);
				c = 1;
			}
		}
		else
			c = 1;
		// on attein ce cas dans le cas lorsque l on arrive dans le cas ou on nous envoi juste le put
		send(server->sock, "200", 3, 0);
		//case where we end this sheat
	}
	return (0);
}
