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
	int c;
	size_t len_header;

	c = 0;
        len_header = ft_strlen(input[0]) + ft_strlen(input[1]) + 2;
        ft_file_write_begin(input[1], &(buffer[(size_t)len_header]), (size_t)size_buf - len_header);
        send(sock, "200", 3, 0);
        while (!c)
        {
                ft_putstr("TURN AROUND THE WORLD ....\n");
                // penser a ajouter un control de parametre si un petit con s amuse trop ...
                size_buf = recv(sock, buffer, SIZE_BUF, 0);
                // case where we write in the thile
                if (size_buf > 3) // when we have data bitch
                {
			//free input
                        input = ft_strsplit_nb_word(buffer, ' ', &(nb_input));
                        //server->num_built = find_builtin(input[0]);
                        if (find_builtin(input[0]) == PUT && nb_input > 2)
                                ft_file_write_end(input[1], &(buffer[(size_t)len_header]), ((size_t)size_buf - len_header));
                        else
                                ft_putstr("|||||||||||| Error ...\n");
                }
                else
                        c = 1;
                // on attein ce cas dans le cas lorsque l on arrive dans le cas ou on nous envoi juste le put
                send(sock, "200", 3, 0);
                //case where we end this sheat
        }
        return (1);
}
