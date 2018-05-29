/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:57:55 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:58:06 by alhelson         ###   ########.fr       */
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

int ft_file_write_begin(char *path, char *data, size_t size);
int ft_file_write_end(char *path, char *data, size_t size);

#endif
