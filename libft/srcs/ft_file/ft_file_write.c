/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:59:33 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/07 18:45:51 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/*
** CRATION D UN FICHIER ET ENREGISTRER LA CHAINE DATA
** 0: good | < 0 error
*/

int		ft_file_write_begin(char *path, char *data, size_t size)
{
	int	fd;
	int	ret;

	if (!path || !data)
		return (-1);
	if ((fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1)
		return (-2);
	if ((ret = write(fd, (void *)data, size)) == -1)
		return (-3);
	close(fd);
	return (0);
}

int		ft_file_write_end(char *path, char *data, size_t size)
{
	int	fd;

	if (!path || !data)
		return (-1);
	if ((fd = open(path, O_APPEND | O_WRONLY, 0777)) == -1)
		return (-2);
	if ((write(fd, data, size)) == -1)
		return (-3);
	close(fd);
	return (fd);
}

/*
** 0 : ecrire en debut en ecransanr
** > 0 : ecrirw a la fin
*/

int		ft_write_file(char *path, char *data, size_t size, int nb)
{
	int ret;

	if (nb == 0)
		ret = ft_file_write_begin(path, data, size);
	else
		ret = ft_file_write_end(path, data, size);
	return (ret);
}
