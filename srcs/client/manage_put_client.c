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

	fd = open(input[1], O_RDONLY); // penser a ajouter tout ce qui est gestion de path ...
	size_header = ft_strlen(input[0]) + ft_strlen(input[1]) + 2;
	ft_strcpy(buffer, input[0]); ft_strcat(buffer, " "); ft_strcat(buffer, input[1]);  ft_strcat(buffer, " "); // put file data
	ft_putstr("Before while .\n");
	while ((len = read(fd, &(buffer[size_header]), SIZE_BUF - size_header)) > 0)
	{
		printf("send : %lu <= %d\n\n", len + size_header, SIZE_BUF);
		if ((send(sock, buffer, len + size_header, 0)) == -1) // send data to server
		{
			ft_putstr("put : error send data\n");
			exit(1);
		}
		ft_putstr("After transmission :\n");
		ret = recv(sock, buffer, SIZE_BUF, 0);
		ft_strcpy(buffer, input[0]); ft_strcat(buffer, " "); ft_strcat(buffer, input[1]);  ft_strcat(buffer, " ");
	}
	// on va envoyer la requete de fin de transmission de fichier
	ft_putstr("Send empty put - end of file\n");
	ft_strcpy(buffer, "put");
	send(sock, buffer, 3, 0);
	close(fd);
	return (1);
}
