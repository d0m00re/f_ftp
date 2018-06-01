#ifndef CLIENT_H
# define CLIENT_H

int main_client(int sock, char *input, char buffer[1024]);

int manage_put_client(int sock, char **input, char buffer[1024]);

int create_client(char *addr, int port);

// afficher des indications sommaire sur la bonne utilisation des commandes
void ft_usage_builtin(int num);

#endif
