/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:11:45 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/17 23:11:58 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s1, const char *s2)
{
	char	*str;
	char	*dest2;

	str = (char *)s2;
	dest2 = s1;
	while (*dest2)
		dest2++;
	while (*str)
	{
		*dest2 = *str;
		dest2++;
		str++;
	}
	*dest2 = '\0';
	return (s1);
}
