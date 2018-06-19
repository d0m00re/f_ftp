/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 06:46:46 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/07 06:53:36 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <string.h>

/*
**	char *name;
**
**	// manage buffer send/recv
**	char buffer[1024];
**        int size_buf;
**
**        char *input;
**        int size_input;
**
**        //
**        char **sp_buffer;
**        int size_sp;
**
**        size_t len_header;
**
**        int running;
**
**        int sock;
*/

typedef struct	s_client
{
	char		*name;
	char		buffer[1024];
	int			size_buf;
	char		*input;
	int			size_input;
	char		**sp_buffer;
	int			size_sp;
	size_t		len_header;
	int			running;
	int			sock;
}				t_client;

typedef struct	s_get_client
{
	char		*cmd;
	char		*name_file;
	char		*header;
	int			len_cmd;
	int			len_name;
	int			len_header;
	char		**sp_buffer;
	int			sp_size;
	int			real_size;
	int			actual_turn;
}				t_get_client;

t_client		*make_client(void);

int				main_client(t_client *client);

int				manage_put_client(t_client *client);
int				manage_get_client(t_client *client);

int				create_client(char *addr, int port);

void			ft_usage_builtin(int num);
void			ft_usage_builtin_store(t_client *client, int num);

int				remaster_prompt(char *str, int size);

int				my_send_and_recv(t_client *client);

int				update_client_and_ret(t_client *client, char *s, int ret);

#endif
