#include "ft_string.h"
#include "ft_display.h"
#include "server.h"
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/socket.h>
#include "ft_file.h"
#include <stdlib.h>

/*int launch_ls_sys()
{
        char *argv[2];

        argv[0] = "ls";
        argv[1] = 0;

        execv("/bin/ls", argv);
        return (1);
}

int launch_ls(char *path)
{
        int res_fils;
        int fd;

        if (fork() == 0)
        {
                fd = open(path, O_CREAT | O_WRONLY, 0777);
                dup2(fd, 1); // old new
                dup2(fd, 2);
                launch_ls_sys();
                close(fd);
        }
        else
        {
                wait(&res_fils);
                //printf("Coucou : %d\n", res_fils);
        }
        return (1);
}

int	ft_ls(t_server *server)
{
	int fd;
	int size_header;
	size_t len;

	launch_ls("/tmp/coucou");
	fd = open("/tmp/coucou", O_RDONLY);
	size_header = 4;
	ft_strcpy(server->buffer, "201 ");
	len = read(fd, &(server->buffer[size_header]), 1024 - size_header);
	send(server->sock, server->buffer, len + size_header, 0);
	return (1);
}
*/

int ft_ls(t_server *server)
{
	int len;
	char *buffer;

	len = 0;
	if (!(buffer = get_rep_string(".", &len)))
	{
		ft_strcpy(server->buffer, "510");
		len = 3;
	}
	else
	{
		ft_strcpy(server->buffer, "200 ");
		ft_strcat(server->buffer, buffer);
		len += 4;
		free(buffer);
	}
	send(server->sock, server->buffer, len, 0);
	return (0);
}
