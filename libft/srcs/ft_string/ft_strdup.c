/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:12:39 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:12:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

char				*ft_strdup(const char *s1)
{
	unsigned int	count;
	char			*str;
	unsigned int	size;

	count = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (0);
	while (s1[count] && count < size)
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
