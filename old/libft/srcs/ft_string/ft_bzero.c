/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:10:17 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:10:54 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}
