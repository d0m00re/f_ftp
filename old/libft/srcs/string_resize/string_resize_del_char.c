/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize_del_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:09:56 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 00:10:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_resize.h"
#include <stdio.h>

int	string_resize_del_char(t_string_resize *st, unsigned int pos)
{
	while (pos < st->len)
	{
		st->str[pos] = st->str[pos + 1];
		pos++;
	}
	if (st->len)
		st->len -= 1;
	else
		return (1);
	return (0);
}
