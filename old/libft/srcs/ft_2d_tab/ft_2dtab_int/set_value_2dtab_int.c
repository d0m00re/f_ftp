/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_2dtab_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:55:53 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 22:56:14 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2dtab_int.h"

int		set_value_2dtab_int(t_2dtab_int *tab, int x, int y, int value)
{
	if (!tab || !(tab->tab) || x < tab->size_x || y < tab->size_y)
		return (1);
	tab->tab[y][x] = value;
	return (0);
}
