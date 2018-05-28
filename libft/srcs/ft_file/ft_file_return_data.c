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

char		*ft_file_return_data(char *name)
{
	char	*str;
	char	c;
	int		count;
	int		size;
	int		fd;

	size = ft_file_size(name);
	if (!name || size <= 0)
		return (0);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	fd = open(name, O_RDONLY);
	count = 0;
	while (read(fd, &c, 1) && count < size)
	{
		str[count] = c;
		count++;
	}
	close(fd);
	str[size - 1] = '\0';
	return (str);
}
