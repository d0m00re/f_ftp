#ifndef CLIENT_H
# define CLIENT_H

# include <string.h>

typedef struct s_client
{
	char *name;

	// manage buffer send/recv
	char buffer[1024];
	int size_buf;

	char *input;
	int size_input;

	//
	char **sp_buffer;
	int size_sp;

	size_t len_header;

	int running;

	int sock;

} t_client;

t_client *make_client(void);

//int main_client(int sock, char *input, char buffer[1024]);
int main_client(t_client *client);

int manage_put_client(t_client *client);//(int sock, char **input, char buffer[1024]);
int manage_get_client(t_client *client);

int create_client(char *addr, int port);

// afficher des indications sommaire sur la bonne utilisation des commandes
void ft_usage_builtin(int num);


int	get_sigint();
void	true_sigint();
void	false_sigint();

#endif
