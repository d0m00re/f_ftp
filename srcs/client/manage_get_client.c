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

int manage_get_client(int sock, char **input, char buffer[1024], size_t size_buf, int nb_input)
{
	char *old_string;
	int c;
	size_t len_header;

	if (nb_input < 2)
		exit(1);
	c = 0;
        len_header = ft_strlen(input[0]) + ft_strlen(input[1]) + 2;
	ft_strcpy(buffer, input[0]);
	ft_strcat(buffer, " ");
	ft_strcat(buffer, input[1]);
	ft_strcat(buffer, " ");
	old_string = ft_strdup(buffer);
	size_buf = send(sock, buffer, 1024, 0);
	size_buf = recv(sock, buffer, 1024, 0);
        ft_file_write_begin(input[1], &(buffer[(size_t)len_header]), (size_t)size_buf - len_header);
	send(sock, old_string, ft_strlen(old_string), 0);
        while (!c)
        {
		// penser a ajouter un control de parametre si un petit con s amuse trop ...
		size_buf = recv(sock, buffer, SIZE_BUF, 0);
		// case where we write in the thile
		if (size_buf > 3) // when we have data bitch
		{
			//free input
			input = ft_strsplit_nb_word(buffer, ' ', &(nb_input));
			//server->num_built = find_builtin(input[0]);
			if (find_builtin(input[0]) == GET && nb_input > 2)
				ft_file_write_end(input[1], &(buffer[(size_t)len_header]), ((size_t)size_buf - len_header));
			else
				ft_putstr("|||||||||||| Error ...\n");
			send(sock, old_string, ft_strlen(old_string), 0);
		}
		else
			c = 1;
                // on attein ce cas dans le cas lorsque l on arrive dans le cas ou on nous envoi juste le put
                //case where we end this sheat
        }
        return (1);
}
