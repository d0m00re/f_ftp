/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 05:12:58 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/28 05:13:10 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)b;
	while (count < len)
	{
		str[count] = c;
		count++;
	}
	return (b);
}
