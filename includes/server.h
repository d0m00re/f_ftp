/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:10:16 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/07 22:35:02 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "string.h"

/*
** MANAGE SERVER FUNCTION
*/

/*
**	int deph; // profondeur permettra de savoir ou on en es
**        char *name; // nom du serveur | nom du repertoire de stoquage
**        char *server; // path de debut de sert
**        char *actual; // emplacement relatif dans le server
**        char *full; // path full with getcwd
**
**        int valid_ftp;
**        int valid_path;
**        int rep_is_create;
**
**        int sock; // socket vers le client
**
**        // gestiob du buffer
**        char buffer[1024];
**        int size_buf;
**
**        // input cast in double char table
**        char **sp_buffer;
**        int size_sp;
**        size_t len_header; // find size of header
**
**        // Builtin
**        int num_built;
**        int num_built_old;
**
**        // 1 : client actif
**        // 2 : fin du client
**        int running;
*/

typedef struct	s_server
{
	int			deph;
	char		*name;
	char		*server;
	char		*actual;
	char		*full;
	int			valid_ftp;
	int			valid_path;
	int			rep_is_create;
	int			sock;
	char		buffer[1024];
	int			size_buf;
	char		**sp_buffer;
	int			size_sp;
	size_t		len_header;
	int			num_built;
	int			num_built_old;
	int			running;
}				t_server;

typedef struct	s_get_server
{
	int			fd;
	char		*cmd;
	char		*name_file;
	char		*header;
	int			len_cmd;
	int			len_name;
	int			len_header;
	char		**sp_buffer;
	int			sp_size;
	int			len;
	int			real_size;
}				t_get_server;

t_server		*server_make(char *server_name);
void			server_make2(t_server *server, char *server_name);

t_get_server	*init_get_server(t_server *server);
void			destroy_get_server(t_get_server *s);

/*
** PATH MANAGE
*/

enum			e_type_builtin {ERROR_CMD, LS, CD, GET, PUT, PWD, QUIT, MKDIR};

int				find_builtin(char *str);

int				ft_put(t_server *server);
int				ft_get(t_server *server);
int				ft_cd(t_server *server);
int				ft_mkdir(t_server *server);
int				ft_ls(t_server *server);
int				ft_pwd(t_server *server);
int				ft_quit(t_server *server);

char			*main_server(t_server *server);

int				create_server(int port);

int				send_and_return(t_server *server, char *str, int len, int ret);

int				check_futur_path(t_server *s);
int				check_futur_path2(t_server *s);

#endif
