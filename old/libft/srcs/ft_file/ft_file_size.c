/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:03:21 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:03:29 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

int			ft_file_size(char *name)
{
	char	c;
	int		fd;
	int		size;
	int		retour;

	retour = ft_file_exist(name);
	size = 0;
	if (!retour)
		return (0);
	fd = open(name, O_RDONLY);
	while (read(fd, &c, 1))
		size++;
	close(fd);
	return (size);
}
