/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextract_before_rchr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:06:35 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/05 23:07:05 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char		*ft_strextract_before_rchr(char *str, char sep)
{
	size_t	len;
	char	*new;
	char	*ref_end;
	size_t	counter;

	counter = 0;
	if (!(ref_end = ft_strrchr(str, sep)))
		return (0);
	len = (size_t)(ref_end - str);
	new = malloc(sizeof(char) * (len + 1));
	while (counter < len)
	{
		new[counter] = str[counter];
		counter++;
	}
	new[counter] = 0;
	return (new);
}
