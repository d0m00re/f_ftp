/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:02:52 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:03:00 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

int		ft_file_exist(char *name)
{
	int	fd;

	if (!name)
		return (0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("ft_file_exist : file not exist\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}
