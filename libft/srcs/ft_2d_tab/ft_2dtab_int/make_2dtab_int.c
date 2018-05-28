/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_2dtab_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:56:25 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 22:56:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2dtab_int.h"

t_2dtab_int		*make_2dtab_int(int x, int y)
{
	int			c;
	t_2dtab_int	*tab;

	if (x < 1 || y < 1 || !(tab = malloc(sizeof(t_2dtab_int))))
		return (0);
	if (!(tab->tab = malloc(sizeof(int *) * y)))
		return (0);
	c = 0;
	while (c < y)
	{
		tab->tab[c] = malloc(sizeof(int) * x);
		c++;
	}
	tab->size_x = x;
	tab->size_y = y;
	return (tab);
}
