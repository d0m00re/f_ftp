/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_2dtab_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:52:41 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 22:54:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_2dtab_int.h"

void	destroy_2dtab_int(t_2dtab_int *tab)
{
	int c;

	if (!tab)
		return ;
	c = 0;
	while (c < tab->size_y)
	{
		free(tab->tab[c]);
		c++;
	}
	free(tab->tab);
	free(tab);
	tab = 0;
}
