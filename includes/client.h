#ifndef CLIENT_H
# define CLIENT_H

int main_client(int sock, char *input, char buffer[1024]);

int manage_put_client(int sock, char **input, char buffer[1024]);

#endif
