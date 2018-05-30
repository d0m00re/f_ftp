/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:10:16 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/29 21:10:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** MANAGE SERVER FUNCTION
*/

typedef struct s_server_integ
{
	int depth;
	char *name_server;
	char *full_path;
	char *full_path_server;

	char *path_actual;

	int valid_ftp;
	int valid_path;
	int rep_is_create;
} t_server_integ;

t_server_integ *server_integ_make(char *name_server);

void		*check_path_server(t_server_integ *serv, char *path);


//checker le path
int check_good_path(t_server_integ *i);

// creer le repertoire d un server
int create_reper_server(t_server_integ *i);


enum	e_type_builtin {ERROR_CMD, LS, CD, GET, PUT, PWD, QUIT};

int		find_builtin(char *str);

int		ft_put(char *name, char *data, unsigned int size, t_server_integ *serv);

char		*main_server(int sock, char *buf, int size, t_server_integ *serv);

int		create_server(int port);

#endif
