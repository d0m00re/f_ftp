/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_return_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:03:06 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:03:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"
#include <stdlib.h>

/*
** a optimiser si on a deja la size on peut utiliser dirrectement la size dans le buffer
** on peut egalement utilisr stat pour obtenir la taille sans lire le fichier
** de la sorte on augmentera fortement la vitesse du bordel
*/
char		*ft_file_return_data_size(char *name, size_t *size)
{
	char	*str;
	char	c;
	unsigned int		count;
	int		fd;

	*size = ft_file_size(name);
	if (!name || *size <= 0)
		return (0);
	str = malloc(sizeof(char) * ((*size) + 1));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	count = 0;
	while (read(fd, &c, 1) && count < (*size))
	{
		str[count] = c;
		count++;
	}
	close(fd);
	str[*size - 1] = '\0';
	return (str);
}

char		*ft_file_return_data(char *name)
{
	size_t size;

	return (ft_file_return_data_size(name, &size));
}
