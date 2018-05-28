/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dtab_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:56:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:57:24 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_2DTAB_INT_H
# define FT_2DTAB_INT_H

# include <stdlib.h>

typedef struct	s_2dtab_int
{
	int			**tab;
	int			size_x;
	int			size_y;
}				t_2dtab_int;

t_2dtab_int		*make_2dtab_int(int x, int y);

void			destroy_2dtab_int(t_2dtab_int *tab);

int				get_value_2dtab_int(t_2dtab_int *tab, int x, int y, int *error);
int				set_value_2dtab_int(t_2dtab_int *tab, int x, int y, int value);

#endif
