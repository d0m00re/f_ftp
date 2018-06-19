/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_with_sep.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 01:56:31 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/01 01:56:41 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char		*ft_concat_with_sep(char *s1, char *s2, char *sep)
{
	char	*tmp;
	size_t	total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 2;
	tmp = malloc(sizeof(char) * total_size);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, sep);
	ft_strcat(tmp, s2);
	return (tmp);
}
