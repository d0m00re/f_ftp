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

# include "string.h"

/*
** MANAGE SERVER FUNCTION
*/

typedef struct s_server
{
	int deph;
	char *name; // nom du serveur
	char *server; //emplacement serveur
	char *actual; // emplacement relatif dans le server
	char *full; // path full with getcwd

	int valid_ftp;
	int valid_path;
	int rep_is_create;

        int sock; // socket vers le client

        // gestiob du buffer
        char buffer[1024];
        int size_buf;

        // input cast in double char table
        char **sp_buffer;
        int size_sp;
        size_t len_header; // find size of header

        // Builtin
        int num_built;
        int num_built_old;

	// 1 : client actif
	// 2 : fin du client
	int running;
} t_server;

t_server *server_make(char *server_name);


//t_server_integ *server_integ_make(char *name_server);

//void		*check_path_server(t_server_integ *serv, char *path);


/*
** PATH MANAGE
*/

//checker le path
//int check_good_path(t_server_integ *i);

// check generate path
//char *generate_path_server_with_name(t_server_integ *serv, char *name);
//char *generate_path_server(t_server_integ *serv);

// creer le repertoire d un server
//int create_reper_server(t_server_integ *i);


enum	e_type_builtin {ERROR_CMD, LS, CD, GET, PUT, PWD, QUIT, MKDIR};

int		find_builtin(char *str);

int		ft_put(t_server *server);
int		ft_get(t_server *server);
int		ft_cd(t_server *server);
int		ft_mkdir(t_server *server);
int		ft_ls(t_server *server);
int		ft_pwd(t_server *server);
int		ft_quit(t_server *server);

char		*main_server(t_server *server);

int		create_server(int port);

#endif
