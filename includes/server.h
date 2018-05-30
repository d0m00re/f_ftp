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
	int depth; // profondeur
	char *name_server; // nom du serveur ftp
	char *full_path; // path comple vers le serveur
	char *full_path_server; // path avec le nom du serveur

	char *path_actual; // path actual dans le serveur
	char *full_path_actual;

	int valid_ftp;
	int valid_path;
	int rep_is_create;

	int sock; // socket vers le client
} t_server_integ;

t_server_integ *server_integ_make(char *name_server);

void		*check_path_server(t_server_integ *serv, char *path);


/*
** PATH MANAGE
*/

//checker le path
int check_good_path(t_server_integ *i);

// check generate path
char *generate_path_server_with_name(t_server_integ *serv, char *name);
char *generate_path_server(t_server_integ *serv);

// creer le repertoire d un server
int create_reper_server(t_server_integ *i);


enum	e_type_builtin {ERROR_CMD, LS, CD, GET, PUT, PWD, QUIT};

int		find_builtin(char *str);

int		ft_put(char *name, char *data, unsigned int size, t_server_integ *serv);

char		*main_server(int sock, char *buf, int size, t_server_integ *serv);

int		create_server(int port);

#endif
