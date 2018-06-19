/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_2dtab_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:55:29 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 22:55:31 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2dtab_int.h"

int	get_value_2dtab_int(t_2dtab_int *tab, int x, int y, int *error)
{
	if (!tab || !(tab->tab) || x < tab->size_x || y < tab->size_y)
	{
		*error = 1;
		return (0);
	}
	return (tab->tab[y][x]);
}
