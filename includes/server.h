#ifndef SERVER_H
# define SERVER_H

enum e_type_builtin {ERROR_CMD, LS, CD, GET, PUT, PWD, QUIT};

int find_builtin(char *str);

int	ft_put(char *name, char *data);

char *main_server(char *buf, int size);

#endif
