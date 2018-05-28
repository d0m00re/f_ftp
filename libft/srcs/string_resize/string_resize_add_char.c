/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize_add_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:48:03 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 00:06:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include <stdlib.h>

/*
** redimen string with size_max + size_max / factor;
*/

void				string_redim(char **str, unsigned int new_size)
{
	unsigned int	c;
	unsigned int	old_size;
	char			*tmp;

	c = 0;
	old_size = ft_strlen(*str);
	tmp = *str;
	*str = malloc(sizeof(char) * (new_size + 1));
	while (c < old_size)
	{
		(*str)[c] = tmp[c];
		c++;
	}
	while (c < (new_size + 1))
	{
		(*str)[c] = '\0';
		c++;
	}
	free(tmp);
}

void				string_resize_redim_string(t_string_resize *t,\
unsigned int factor)
{
	t->len_max = t->len_max + (t->len_max / factor);
	string_redim(&(t->str), t->len_max);
}

void				string_resize_decal_droite(char **str,\
int size, int pos)
{
	(*str)[size + 1] = '\0';
	while (size > pos)
	{
		(*str)[size] = (*str)[size - 1];
		size--;
	}
}

int					string_resize_add_char(t_string_resize *st,\
		unsigned int pos, char c)
{
	if (!st || st->len > st->len_max)
		return (1);
	if (st->len == st->len_max - 1)
		string_resize_redim_string(st, 2);
	if (pos < st->len)
		string_resize_decal_droite(&(st->str), st->len, pos);
	st->str[pos] = c;
	st->len += 1;
	return (0);
}
