#ifndef CLIENT_H
# define CLIENT_H

# include <string.h>

int main_client(int sock, char *input, char buffer[1024]);

int manage_put_client(int sock, char **input, char buffer[1024]);
int manage_get_client(int sock, char **input, char buffer[1024], size_t size_buf, int nb_input);

int create_client(char *addr, int port);

// afficher des indications sommaire sur la bonne utilisation des commandes
void ft_usage_builtin(int num);


int	get_sigint();
void	true_sigint();
void	false_sigint();

#endif
