/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 05:35:33 by alhelson          #+#    #+#             */
/*   Updated: 2018/06/04 05:36:46 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (0);
}

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		size;

	if (!s)
		return (0);
	size = ft_strlen(s) - 1;
	str = (char *)s;
	while (size >= 0)
	{
		if (str[size] == (char)c)
			return (&(str[size]));
		size--;
	}
	return (0);
}

/*
** int main()
** {
**	char *s = "coucou/var/en/coucou/john";
**
**	printf("--> %s\n --> %s\n --> %s\n --> %s\n",
**  s, ft_strchr(s, '/'), ft_strrchr(s, '/'), ft_strrchr(s, '*'));
**	return (0);	
** }
*/
