#include <stdlib.h>
#include "client.h"
#include "ft_string.h"

t_client *make_client(void)
{
	t_client *client;

	if (!(client = malloc(sizeof(t_client))))
		return (0);
	ft_bzero(client, sizeof(t_client));
	client->running = 1;
	return (client);
}
