#include "client.h"
#include "ft_file.h"
#include <string.h>
#include <stdio.h>
#include "ft_string.h"
#include <stdlib.h>
#include <sys/socket.h>
#include "setting.h"
#include "ft_display.h"

// formatage de l input
// input [name_file] [data]
// nom du ficher
// data fichier local
// curseur actuel
// size du fichier max
// size du buffer a envoye

int manage_put_client(int sock, char **input, char buffer[1024])
{
	size_t len;
	int fd;
	int size_header;
	int ret;

	if ((fd = open(input[1], O_RDONLY)) == -1)
	{
		ft_putstr("manage_put_client : error open file.\n");
		exit(1);
	}
	size_header = ft_strlen(input[0]) + ft_strlen(input[1]) + 2;
	concat_2dchar_in_buffer(buffer, input, 2, " ");
	while ((len = read(fd, &(buffer[size_header]), SIZE_BUF - size_header)) > 0)
	{
		if ((send(sock, buffer, len + size_header, 0)) == -1) // send data to server
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		if ((ret = recv(sock, buffer, SIZE_BUF, 0)) == -1)
		{
			ft_putstr("put ; error recv data\n");
			exit(1);
		}
		concat_2dchar_in_buffer(buffer, input, 2, " ");
	}
	ft_strcpy(buffer, "put");
	if ((send(sock, buffer, 3, 0)) == -1)
		ft_putstr("put : error send last message\n");
	close(fd);
	return (1);
}
