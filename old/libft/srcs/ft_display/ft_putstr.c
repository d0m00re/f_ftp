/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:02:26 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:02:28 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "ft_string.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int size;

	if (!s || fd < 0)
		return ;
	size = ft_strlen(s);
	if (size < 1)
		return ;
	write(fd, s, size);
}

void	ft_putstr_limit(char const *s, size_t size)
{
	write(1, s, size);
}

void	ft_putstr(char const *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_putstr_fd_endl(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putstr_endl(char const *s)
{
	ft_putstr_fd_endl(s, 1);
}
