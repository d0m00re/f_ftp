/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:00:31 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 16:01:41 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** purpose : strin resize in each size, can improve buffer size
*/

#ifndef STRING_RESIZE_H
# define STRING_RESIZE_H
# include "ft_string.h"

typedef struct		s_string_resize
{
	char			*str;
	unsigned int	len;
	unsigned int	len_max;
}					t_string_resize;

/*
** init data structure
*/

t_string_resize		*string_resize_make(unsigned int len_max);

t_string_resize		*string_resize_make_with_str(unsigned int len_max,\
		char *str);

/*
** destroy
*/

void				string_resize_destroy(t_string_resize *st);

/*
** add char in string at certain pos
** 1 : error
** 0 : good
*/

void				string_resize_redim_string(t_string_resize *t,\
		unsigned int factor);
int					string_resize_add_char(t_string_resize *st,\
		unsigned int pos, char c);

/*
** delete char in string at certein pos
** 1 : error
** 0 : good
*/

int					string_resize_del_char(t_string_resize *st,\
		unsigned int pos);

#endif
