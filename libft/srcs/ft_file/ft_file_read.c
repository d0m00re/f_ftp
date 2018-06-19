/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:57:50 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 01:59:14 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char			*ft_read_file_size(char *path, size_t *size)
{
	struct stat	sb;
	char		*str;
	int			fd;

	if (!path)
		return (0);
	if (lstat(path, &sb) == -1)
		return (0);
	if (sb.st_mode != S_IFREG)
		return (0);
	*size = sb.st_size;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if ((str = malloc((*size + 1) * sizeof(char))) == 0)
		return (0);
	if ((read(fd, str, *size)) == -1)
		return (0);
	str[*size - 1] = 0;
	return (str);
}

char			*ft_read_file(char *path)
{
	size_t		size;

	return (ft_read_file_size(path, &size));
}
