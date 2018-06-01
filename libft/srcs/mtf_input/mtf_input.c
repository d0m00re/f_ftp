/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtf_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 02:03:31 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 02:03:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_display.h"
#define MAX_SIZE 1000

int			ft_clear_buffer(void)
{
	char	c;
	int		count;

	count = 0;
	while (read(0, &c, 1) && c > 0 && c != 10 && count < 2000000000)
		count++;
	return (count);
}

char		*ft_read_standart_input(void)
{
	char	*tab;
	int		c;
	char	ca;

	c = 0;
	if (!(tab = malloc(sizeof(char) * (MAX_SIZE + 1))))
		return (0);
	ft_memset(tab, 0, MAX_SIZE + 1);
	while (read(0, &ca, 1) && c < MAX_SIZE && ca != 10 && ca != -1)
	{
		tab[c] = ca;
		c++;
	}
	if (ca != 10 && ft_clear_buffer() > 1)
	{
		free(tab);
		tab = 0;
	}
	return (tab);
}

char		*main_input(void)
{
	char	*line;

	line = 0;
	write(1, "$>", 2);
	if (!(line = ft_read_standart_input()))
		ft_putstr_fd("OMG : error line_command\n", 2);
	return (line);
}
