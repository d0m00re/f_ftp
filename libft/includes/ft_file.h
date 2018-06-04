/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:57:55 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 02:04:16 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include <fcntl.h>
# include <unistd.h>

int		ft_file_exist(char *name);

int		ft_file_size(char *name);

char	*ft_file_return_data_size(char *name, size_t *size);
char	*ft_file_return_data(char *name);

/*
** READ FILE
*/

char	*ft_read_file_size(char *path, size_t *size);
char	*ft_read_file(char *path);

/*
** WRITE FILE
*/

int		ft_file_write_begin(char *path, char *data, size_t size);
int		ft_file_write_end(char *path, char *data, size_t size);

/*
** REPERTORIES MANAGE
*/

/*
** FILE AND REPERTORIES
*/

int rep_exist(char *name);
int get_rep_size_without_hide(char *name);
char *get_rep_string_without_hide_with_size(char *name, int len);
char *get_rep_string(char *name, int *len);

/*
** checker if path if no dessendant ~
*/

char	*get_rep_with_pathname(char *target);
int	valid_path_no_dess(char *actual_path, char *target);
int	valid_path_no_dess_auto(char *target);

/*
** CHECK FILE TYPE
*/

int	is_rep(const char *path);
int	is_file(const char *path);
int	is_type_file_exist(const char *path);
int	is_not_file_but_other(const char *path);

#endif
