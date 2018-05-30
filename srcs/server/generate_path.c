#include "server.h"
#include "ft_string.h"
#include <stdlib.h>

char *generate_path_server(t_server_integ *serv)
{
	char *path;
	size_t size;

	size = ft_strlen(serv->full_path_server) + ft_strlen(serv->path_actual) + 1;
	if (!(path = malloc(sizeof(char) * size)))
		return (0);
	ft_strcpy(path, serv->full_path_server);
	ft_strcat(path, serv->path_actual);
	return (path);
}

char *generate_path_server_with_name(t_server_integ *serv, char *name)
{
	char *path;
	size_t size;

	size = ft_strlen(serv->full_path_server) + ft_strlen(serv->path_actual) + ft_strlen(name) + 3;
	if (!(path = malloc(sizeof(char) * size)))
		return (0);
	ft_strcpy(path, serv->full_path_server);
	ft_strcat(path, serv->path_actual);
	ft_strcat(path, "/");
	ft_strcat(path, name);
	return (path);
}
