/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string_diff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:55:25 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 01:56:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_display.h"

/*
** main : /Users/alhelson/workflow/ma_bite/test_server/beatiful_server
** last : /Users/alhelson/workflow/ma_bite/test_server/beatiful_server/dude
*/

char		*extract_string_diff(char *main, char *last)
{
	size_t	s1;
	size_t	s2;
	size_t	count;
	char	*new;

	if (!main || !last)
	{
		ft_putstr("|||||| extract string diff error ...\n");
		return (0);
	}
	count = 0;
	s1 = ft_strlen(main);
	s2 = ft_strlen(last);
	if (s1 >= s2)
		return (0);
	if (!(new = malloc(sizeof(char) * (s2 - s1 + 1))))
		return (0);
	ft_putchar('a');
	while (s1 + count < s2)
	{
		ft_putchar('O');
		new[count] = last[s1 + count];
		count++;
	}
	ft_putchar('x');
	new[count] = 0;
	ft_putchar('|');
	return (new);
}
